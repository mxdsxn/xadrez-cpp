#include "./Peao.h"
#include <iostream>

using namespace std;

Peao::Peao(string estilo, bool sentidoPraFrente) : Peca(estilo, sentidoPraFrente)
{
  this->simbolo = this->estilo == "preto" ? "♙" : "♟";
  this->primeiraJogada = true;
}
Peao::~Peao() {}

vector<Posicao *> Peao::getPosicoesValidas(vector<vector<Posicao *>> *posicoesTabuleiro)
{
  vector<Posicao *> posicoesValidas;
  if (this)
  {
    int limiteTabuleiro = 8;
    int xPosicao, yPosicao;
    bool sentidoPraFrente = this->sentidoPraFrente;
    Posicao *posicaoAtualPeca = this->posicao;

    // Posicao a frente - 1 casa pra frente se estiver vazia
    xPosicao = posicaoAtualPeca->getX();
    yPosicao = posicaoAtualPeca->getY() + (sentidoPraFrente ? 1 : -1);
    Posicao *posicaoFrente = (*posicoesTabuleiro)[yPosicao][xPosicao];

    Peca *pecaPosicaoFrente = posicaoFrente->getPecaAtual();
    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (pecaPosicaoFrente == nullptr))
    {
      posicoesValidas.push_back(posicaoFrente);

      // Posicao a frente(primeira jogada) - 2 casa pra frente se estiver vazia
      if (this->primeiraJogada)
      {
        xPosicao = posicaoAtualPeca->getX();
        yPosicao = posicaoAtualPeca->getY() + (sentidoPraFrente ? 2 : -2);
        Posicao *posicaoFrentePrimeiraJogada = (*posicoesTabuleiro)[yPosicao][xPosicao];

        Peca *pecaPosicaoFrentePrimeiraJogada = posicaoFrentePrimeiraJogada->getPecaAtual();
        if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (pecaPosicaoFrentePrimeiraJogada == nullptr))
        {
          posicoesValidas.push_back(posicaoFrentePrimeiraJogada);
        }
      }
    }

    // Posicao a diagonal esquerda - 1 casa pra frente e a esquerda se estiver com uma peça de oponente
    xPosicao = posicaoAtualPeca->getX() + (sentidoPraFrente ? -1 : 1);
    yPosicao = posicaoAtualPeca->getY() + (sentidoPraFrente ? 1 : -1);
    Posicao *posicaoDiagonalEsquerda = (*posicoesTabuleiro)[yPosicao][xPosicao];

    Peca *pecaPosicaoDiagonalEsquerda = posicaoDiagonalEsquerda->getPecaAtual();
    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro) && (pecaPosicaoDiagonalEsquerda->getEstilo() != this->estilo) && (pecaPosicaoDiagonalEsquerda != nullptr))
    {
      posicoesValidas.push_back(posicaoDiagonalEsquerda);
    }

    // Posicao a diagonal direita - 1 casa pra frente e a direita se estiver com uma peça de oponente
    xPosicao = posicaoAtualPeca->getX() + (sentidoPraFrente ? 1 : -1);
    yPosicao = posicaoAtualPeca->getY() + (sentidoPraFrente ? 1 : -1);
    Posicao *posicaoDiagonalDireita = (*posicoesTabuleiro)[yPosicao][xPosicao];

    Peca *pecaPosicaoDiagonalDireita = posicaoDiagonalDireita->getPecaAtual();
    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro) && (pecaPosicaoDiagonalDireita->getEstilo() != this->estilo) && (pecaPosicaoDiagonalDireita != nullptr))
    {
      posicoesValidas.push_back(posicaoDiagonalDireita);
    }
  }

  return posicoesValidas;
}
