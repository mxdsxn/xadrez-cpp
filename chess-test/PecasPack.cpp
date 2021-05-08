#include "./PecasPack.h"
#include "./Peao.h"
#include "./Rei.h"
#include <iostream>
#include "./utils.h"

PecasPack::PecasPack(string estilo, bool sentidoPraFrente, Tabuleiro *tabuleiro)
{
  this->estilo = estilo;

  // instancia os peoes
  for (int i = 1; i <= 8; i++)
  {
    Peao *novoPeao = new Peao(estilo, sentidoPraFrente);
    this->peoes.push_back(novoPeao);
    this->tabuleiro = tabuleiro;
  }

  /*
    // instancia os torres
    for (int i = 1; i <= 2; i++)
    {
        Torre *novaTorre = new Torre(estilo);
        this->torres.push_back(novaTorre);
    }

    // instancia os bispos
    for (int i = 1; i <= 2; i++)
    {
        Bispo *novoBispo = new Bispo(estilo);
        this->bispos.push_back(novoBispo);
    }

    // instancia os cavalos
    for (int i = 1; i <= 2; i++)
    {
        Cavalo *novoCavalo = new Cavalo(estilo);
        this->cavalos.push_back(novoCavalo);
    }

    // instancia rei e rainha
    this->rainha = new Rainha(estilo);*/
  this->rei = new Rei(estilo, sentidoPraFrente);
}

PecasPack::~PecasPack()
{
}

vector<Peca *> PecasPack::getPecasDisponiveis()
{
  vector<Peca *> pecasDisponiveis;

  // Caso o Rei esteja em Xeque, apenas ele é enviado como peça disponivel
  if (this->rei->getPosicaoAtual() != nullptr)
  {
    pecasDisponiveis.push_back(this->rei);
    if (this->rei->getXeque())
    {
      return pecasDisponiveis;
    }
  }

  for (int indice = 0; indice < this->peoes.size(); indice++)
  {
    Peca *peaoAtual = this->peoes[indice];
    if (peaoAtual && peaoAtual->getPosicaoAtual() != nullptr)
    {
      pecasDisponiveis.push_back(peaoAtual);
    }
  }

  return pecasDisponiveis;
}

string PecasPack::getEstilo()
{
  if (this)
  {
    return this->estilo;
  }
  return "";
}

void PecasPack::setPosicaoInicialRealeza(vector<Posicao *> *linhaInicialRealeza)
{
  vector<Peca *> pecasRealeza;

  pecasRealeza.push_back(nullptr);
  pecasRealeza.push_back(nullptr);
  pecasRealeza.push_back(nullptr);
  pecasRealeza.push_back(nullptr);
  pecasRealeza.push_back(this->rei);
  pecasRealeza.push_back(nullptr);
  pecasRealeza.push_back(nullptr);
  pecasRealeza.push_back(nullptr);

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

Posicao *PecasPack::getPosicaoRei()
{
  if (this)
  {
    return this->rei->getPosicaoAtual();
  }
  return nullptr;
}

bool PecasPack::verificaXequeAdversario(Posicao *posicaoReiAdversario)
{
  if (this)
  {
    vector<Posicao *> jogadasDisponiveisTodasPecas;
    vector<vector<Posicao *>> *matrizPosicoesTabuleiro = this->tabuleiro->getTodasPosicoes();

    // verifica se algum peao coloca o rei em xeque
    for (int indice = 0; indice < this->peoes.size(); indice++)
    {
      Peca *peaoAtual = this->peoes[indice];
      bool pecaAtualColocaEmXeque = peaoAtual->verificaXequeAdversario(posicaoReiAdversario, matrizPosicoesTabuleiro);

      // caso peao coloque o rei em xeque, returna TRUE
      if (pecaAtualColocaEmXeque)
      {
        return pecaAtualColocaEmXeque;
      }
    }
  }
  return false;
}

void PecasPack::setXeque(bool emXeque)
{
  if (this)
  {
    this->emXeque = emXeque;
    this->rei->setXeque(emXeque);
  }
}
