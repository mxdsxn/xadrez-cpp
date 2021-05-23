#include <iostream>
#include "./PecasPack.h"
#include "../pecas/pecaPeao/Peao.h"
#include "../pecas/pecaRei/Rei.h"
#include "../pecas/pecaRainha/Rainha.h"
#include "../pecas/pecaTorre/Torre.h"
#include "../pecas/pecaBispo/Bispo.h"
#include "../pecas/pecaCavalo/Cavalo.h"
#include "../utils/utils.h"
#include "../pecas/pecaDAO/PecaDAO.h"

PecasPack::PecasPack(string estilo, bool sentidoPraFrente, Tabuleiro *tabuleiro)
{
  this->estilo = estilo;
  this->tabuleiro = tabuleiro;
  this->pacotePecasDAO = new PacotePecasDAO();
  this->sql_idPacotePeca = -1;

  // instancia os peoes
  for (int i = 1; i <= 8; i++)
  {
    Peao *novoPeao = new Peao(estilo, sentidoPraFrente);
    this->peoes.push_back(novoPeao);
  }

  // instancia os torres
  for (int i = 1; i <= 2; i++)
  {
    Torre *novaTorre = new Torre(estilo, sentidoPraFrente);
    this->torres.push_back(novaTorre);
  }

  // instancia os bispos
  for (int i = 1; i <= 2; i++)
  {
    Bispo *novoBispo = new Bispo(estilo, sentidoPraFrente);
    this->bispos.push_back(novoBispo);
  }

  // instancia os cavalos
  for (int i = 1; i <= 2; i++)
  {
    Cavalo *novoCavalo = new Cavalo(estilo, sentidoPraFrente);
    this->cavalos.push_back(novoCavalo);
  }

  // instancia rei e rainha
  this->rei = new Rei(estilo, sentidoPraFrente);
  this->rainha = new Rainha(estilo, sentidoPraFrente);
}

PecasPack::PecasPack(int idPacotePeca, bool emXeque, string estilo)
{
  this->sql_idPacotePeca = idPacotePeca;
  this->emXeque = emXeque;
  this->estilo = estilo;
  this->pacotePecasDAO = new PacotePecasDAO();

  this->rei = nullptr;
  this->rainha = nullptr;
  this->tabuleiro = nullptr;

  PecaDAO *pecaDAO = new PecaDAO();
  vector<Peca *> listaPecas = pecaDAO->recuperar(idPacotePeca);

  for (int indice = 0; indice < listaPecas.size(); indice++)
  {
    Peca *pecaAtual = listaPecas[indice];
    switch (pecaAtual->getCodigo())
    {
    case 1:
      if (this->rei == nullptr)
        this->rei = pecaAtual;
      break;
    case 2:
      if (this->rainha == nullptr)
        this->rainha = pecaAtual;
      break;
    case 3:
      this->cavalos.push_back(pecaAtual);
      break;
    case 4:
      this->bispos.push_back(pecaAtual);
      break;
    case 5:
      this->torres.push_back(pecaAtual);
      break;
    case 6:
      this->peoes.push_back(pecaAtual);
      break;
    default:
      this->peoes.push_back(pecaAtual);
      break;
    }
  }
}

PecasPack::~PecasPack() {}

string PecasPack::getEstilo()
{
  if (this)
  {
    return this->estilo;
  }
  return "";
}

Posicao *PecasPack::getPosicaoRei()
{
  if (this)
  {
    return this->rei->getPosicaoAtual();
  }
  return nullptr;
}

vector<Peca *> PecasPack::getTodasPecas()
{
  vector<Peca *> todasPecas;

  if (this)
  {
    // peoes
    todasPecas.insert(todasPecas.end(), this->peoes.begin(), this->peoes.end());

    // torres
    todasPecas.insert(todasPecas.end(), this->torres.begin(), this->torres.end());

    // bispos
    todasPecas.insert(todasPecas.end(), this->bispos.begin(), this->bispos.end());

    // cavalos
    todasPecas.insert(todasPecas.end(), this->cavalos.begin(), this->cavalos.end());

    // rei
    todasPecas.push_back(this->rei);
    // rainha
    todasPecas.push_back(this->rainha);
  }

  return todasPecas;
}

vector<Peca *> PecasPack::getPecasDisponiveisJogadas(vector<vector<Posicao *>> *posicoesTabuleiro)
{
  vector<Peca *> pecasDisponiveis;
  vector<Peca *> todasPecas = this->getTodasPecas();

  // Todas as peças sao requisitadas e validadas, se estão disponiveis no tabuleiro ou foram capturadas
  for (int indice = 0; indice < todasPecas.size(); indice++)
  {
    Peca *pecaAtual = todasPecas[indice];
    if (pecaAtual && pecaAtual->getPosicaoAtual() != nullptr && pecaAtual->verificaDisponibilidadeMovimentar(posicoesTabuleiro))
    {
      pecasDisponiveis.push_back(pecaAtual);
    }
  }

  return pecasDisponiveis;
}

vector<Posicao *> PecasPack::getJogadasDisponiveisFiltrandoRiscoXeque(Peca *pecaSelecionadaAdversario)
{
  vector<vector<Posicao *>> *matrizPosicoesTabuleiro = this->tabuleiro->getTodasPosicoes();
  vector<Posicao *> jogadasDisponiveisAdversario = pecaSelecionadaAdversario->getTodasJogadasDisponiveis(matrizPosicoesTabuleiro);
  vector<Posicao *> jogadasFiltradasAdversario;

  Tabuleiro *tabuleiro = this->tabuleiro;
  PecasPack *pecasAdversario = (pecaSelecionadaAdversario->getSentidoPraFrente())
                                   ? tabuleiro->getPecasBrancas()
                                   : tabuleiro->getPecasPretas();

  // Posicao atual do rei adversario. Rei esse que PODE VIR correr risco de xeque, caso uma jogada nao permitida seja executada
  Posicao *posicaoReiAdversario = nullptr;

  for (int indice = 0; indice < jogadasDisponiveisAdversario.size(); indice++)
  {

    Posicao *possivelJogadaAdversario = jogadasDisponiveisAdversario[indice];

    Peca *pecaPossivelJogadaTmp = possivelJogadaAdversario->getPecaAtual();
    Posicao *antigaPosicaoPecaSelecionadaAdversarioTmp = pecaSelecionadaAdversario->getPosicaoAtual();

    pecaSelecionadaAdversario->movimentar(possivelJogadaAdversario, true);

    posicaoReiAdversario = pecasAdversario->getPosicaoRei();

    // Rei da do Adversario
    bool reiEmXeque = this->verificaReiAdversarioXeque(posicaoReiAdversario);
    if (!reiEmXeque)
    {
      jogadasFiltradasAdversario.push_back(possivelJogadaAdversario);
    }

    // Restaura simulacao
    pecaSelecionadaAdversario->movimentar(antigaPosicaoPecaSelecionadaAdversarioTmp, true);
    pecaPossivelJogadaTmp->movimentar(possivelJogadaAdversario, true);
  }

  return jogadasFiltradasAdversario;
}

void PecasPack::setXeque(bool emXeque)
{
  if (this)
  {
    this->emXeque = emXeque;
    this->rei->setXeque(emXeque);
  }
}

bool PecasPack::getXeque()
{
  if (this)
  {
    return this->emXeque;
  }
  return false;
}

void PecasPack::setTabuleiro(Tabuleiro *tabuleiro)
{
  if (this)
  {
    this->tabuleiro = tabuleiro;
  }
}

void PecasPack::setPosicaoInicialPeoes(vector<Posicao *> *linhaInicialPeoes)
{
  vector<Peca *> *peoes = &(this->peoes);
  for (int indice = 0; indice < 8; indice++)
  {
    Posicao *posicaoAtual = (*linhaInicialPeoes)[indice];
    Peca *pecaAtual = (*peoes)[indice];
    //setta peça na posicao
    posicaoAtual->setPeca(pecaAtual);

    //setta posicao na peça
    pecaAtual->setPosicao(posicaoAtual);
  }
}

void PecasPack::setPosicaoInicialRealeza(vector<Posicao *> *linhaInicialRealeza)
{
  vector<Peca *> pecasRealeza;

  pecasRealeza.push_back(this->torres[0]);
  pecasRealeza.push_back(this->cavalos[0]);
  pecasRealeza.push_back(this->bispos[0]);
  pecasRealeza.push_back(this->rainha);
  pecasRealeza.push_back(this->rei);
  pecasRealeza.push_back(this->bispos[1]);
  pecasRealeza.push_back(this->cavalos[1]);
  pecasRealeza.push_back(this->torres[1]);

  for (int indice = 0; indice < 8; indice++)
  {
    Posicao *posicaoAtual = (*linhaInicialRealeza)[indice];
    Peca *pecaAtual = pecasRealeza[indice];

    if (pecaAtual != nullptr)
    {
      //setta peça na posicao
      posicaoAtual->setPeca(pecaAtual);

      //setta posicao na peça
      pecaAtual->setPosicao(posicaoAtual);
    }
  }
}

bool PecasPack::verificaReiAdversarioXeque(Posicao *posicaoReiAdversario)
{
  if (this)
  {
    vector<Posicao *> jogadasDisponiveisTodasPecas;
    vector<vector<Posicao *>> *matrizPosicoesTabuleiro = this->tabuleiro->getTodasPosicoes();
    vector<Peca *> todasPecas = this->getTodasPecas();

    // verifica se algum peao coloca o rei em xeque
    for (int indice = 0; indice < todasPecas.size(); indice++)
    {
      Peca *pecaAtual = todasPecas[indice];
      bool pecaAtualColocaEmXeque = pecaAtual->verificaReiAdversarioXeque(posicaoReiAdversario, matrizPosicoesTabuleiro);

      // caso peao coloque o rei em xeque, returna TRUE
      if (pecaAtualColocaEmXeque)
      {
        return pecaAtualColocaEmXeque;
      }
    }
  }
  return false;
}

int PecasPack::salvar(int idJogador)
{
  if (this)
  {
    return this->pacotePecasDAO->salvar(idJogador, this);
  }

  return 0;
}

void PecasPack::deletar()
{
  if (this->sql_idPacotePeca != -1)
  {
    vector<Peca *> listaPeca = this->getTodasPecas();

    for (int indice = 0; indice < listaPeca.size(); indice++)
    {
      listaPeca[indice]->deletar();
    }

    this->pacotePecasDAO->deletar(this);
  }
}

int PecasPack::getSqlIdPacotePeca()
{
  if (this)
  {
    return this->sql_idPacotePeca;
  }
  return -1;
}
