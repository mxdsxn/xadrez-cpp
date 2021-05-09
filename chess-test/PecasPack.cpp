#include "./PecasPack.h"
#include "./Peao.h"
#include "./Rei.h"
#include "./Rainha.h"
#include "./Torre.h"
#include "./Bispo.h"
#include <iostream>
#include "./utils.h"

PecasPack::PecasPack(string estilo, bool sentidoPraFrente, Tabuleiro *tabuleiro)
{
  this->estilo = estilo;
  this->tabuleiro = tabuleiro;

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

  /*
    // instancia os cavalos
    for (int i = 1; i <= 2; i++)
    {
        Cavalo *novoCavalo = new Cavalo(estilo);
        this->cavalos.push_back(novoCavalo);
    }*/

  // instancia rei e rainha
  this->rei = new Rei(estilo, sentidoPraFrente);
  this->rainha = new Rainha(estilo, sentidoPraFrente);
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
    //todasPecass.insert(todasPecas.end(),this->cavalos.begin(),this->cavalos.end());

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

  // Caso o Rei esteja em Xeque, apenas ele é enviado como peça disponivel
  if (this->rei->getPosicaoAtual() != nullptr)
  {
    if (this->rei->getXeque())
    {
      pecasDisponiveis.push_back(this->rei);
      return pecasDisponiveis;
    }
  }

  // Caso contrario, todas as peças sao requisitadas e validadas, se estão disponiveis no tabuleiro ou foram capturadas
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

  /*
  cout << ">estilo pacote analisando: " << this->getEstilo() << endl;
  cout << "*estilo pecaSelecionada: " << pecaSelecionadaAdversario->getEstilo() << endl;
  cout << "*estilo pacote pecaSelecionada: " << pecasAdversario->getEstilo() << endl;
  cout << "*sentido pecaSelecionada: " << ((pecaSelecionadaAdversario->getSentidoPraFrente()) ? "frente" : "tras") << endl;
  */

  // Posicao atual do rei adversario. Rei esse que PODE VIR correr risco de xeque, caso uma jogada nao permitida seja executada
  Posicao *posicaoReiAdversario = nullptr;

  for (int indice = 0; indice < jogadasDisponiveisAdversario.size(); indice++)
  {

    Posicao *possivelJogadaAdversario = jogadasDisponiveisAdversario[indice];

    Peca *pecaPossivelJogadaTmp = possivelJogadaAdversario->getPecaAtual();
    Posicao *antigaPosicaoPecaSelecionadaAdversarioTmp = pecaSelecionadaAdversario->getPosicaoAtual();

    pecaSelecionadaAdversario->movimentar(possivelJogadaAdversario);
    //this->tabuleiro->show(pecaSelecionadaAdversario->getSentidoPraFrente());

    posicaoReiAdversario = pecasAdversario->getPosicaoRei();

    /*
    cout << "endereco pecaSelecionada "
         << pecaSelecionadaAdversario << " "
         << pecaSelecionadaAdversario->getCodigo() << " "
         << pecaSelecionadaAdversario->getEstilo() << " "
         << pecaSelecionadaAdversario->getSimbolo() << " "
         << endl;

    cout << "endereco rei adversario "
         << posicaoReiAdversario->getPecaAtual() << " "
         << posicaoReiAdversario->getPecaAtual()->getCodigo() << " "
         << posicaoReiAdversario->getPecaAtual()->getEstilo() << " "
         << posicaoReiAdversario->getPecaAtual()->getSimbolo() << " "
         << endl;

    cout << "jogada em analise: " << formataCoordenadas(posicaoToCoordStr(possivelJogadaAdversario)) << endl;
    */

    // Rei da do Adversario
    bool reiEmXeque = this->verificaReiAdversarioXeque(posicaoReiAdversario);
    if (!reiEmXeque)
    {
      jogadasFiltradasAdversario.push_back(possivelJogadaAdversario);
    }

    /*
    cout << "Rei fica em xeque apos essa jogada: " << (reiEmXeque ? "sim" : "nao") << endl;
    cleanBuffer();
    */

    // Restaura simulacao
    pecaSelecionadaAdversario->movimentar(antigaPosicaoPecaSelecionadaAdversarioTmp);
    pecaPossivelJogadaTmp->movimentar(possivelJogadaAdversario);
    //this->tabuleiro->show(!pecaSelecionadaAdversario->getSentidoPraFrente());
    //cleanBuffer();
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
  pecasRealeza.push_back(nullptr);
  pecasRealeza.push_back(this->bispos[0]);
  pecasRealeza.push_back(this->rainha);
  pecasRealeza.push_back(this->rei);
  pecasRealeza.push_back(this->bispos[1]);
  pecasRealeza.push_back(nullptr);
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
