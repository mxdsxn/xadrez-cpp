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

    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (posicaoFrente->getPecaAtual() == nullptr))
    {
      posicoesValidas.push_back(posicaoFrente);

      // Posicao a frente(primeira jogada) - 2 casa pra frente se estiver vazia
      if (this->primeiraJogada)
      {
        xPosicao = posicaoAtualPeca->getX();
        yPosicao = posicaoAtualPeca->getY() + (sentidoPraFrente ? 2 : -2);
        Posicao *posicaoFrentePrimeiraJogada = (*posicoesTabuleiro)[yPosicao][xPosicao];

        if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (posicaoFrentePrimeiraJogada->getPecaAtual() == nullptr))
        {
          posicoesValidas.push_back(posicaoFrentePrimeiraJogada);
        }
      }
    }

    // Posicao a diagonal esquerda - 1 casa pra frente se estiver vazia
    xPosicao = posicaoAtualPeca->getX() + (sentidoPraFrente ? -1 : 1);
    yPosicao = posicaoAtualPeca->getY() + (sentidoPraFrente ? 1 : -1);
    Posicao *posicaoDiagonalEsquerda = (*posicoesTabuleiro)[yPosicao][xPosicao];

    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro) && (posicaoDiagonalEsquerda->getPecaAtual() != nullptr))
    {
      posicoesValidas.push_back(posicaoDiagonalEsquerda);
    }

    // Posicao a diagonal direita - 1 casa pra frente se estiver vazia
    xPosicao = posicaoAtualPeca->getX() + (sentidoPraFrente ? 1 : -1);
    yPosicao = posicaoAtualPeca->getY() + (sentidoPraFrente ? 1 : -1);
    Posicao *posicaoDiagonalDireita = (*posicoesTabuleiro)[yPosicao][xPosicao];

    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro) && (posicaoDiagonalDireita->getPecaAtual() != nullptr))
    {
      posicoesValidas.push_back(posicaoDiagonalDireita);
    }
  }

  return posicoesValidas;
}
