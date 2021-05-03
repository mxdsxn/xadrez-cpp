#include "PecasPack.h"

PecasPack::PecasPack(string estilo, bool sentidoJogador1)
{
  this->estilo = estilo;

  // instancia os peoes
  for (int i = 1; i <= 8; i++)
  {
    Peao *novoPeao = new Peao(estilo, sentidoJogador1);
    this->peoes.push_back(novoPeao);
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
    this->rainha = new Rainha(estilo);
    this->rei = new Rei(estilo);*/
}

PecasPack::~PecasPack()
{
}

//vector<Peca *> PecasPack::getPecasDisponiveis(){}

string PecasPack::getEstilo()
{
  if (this)
  {
    return this->estilo;
  }
  return "";
}

void PecasPack::setPosicaoIncialPeoes(vector<Posicao *> *linhaInicialPeoes)
{
  vector<Peao *> *peoes = &(this->peoes);
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
