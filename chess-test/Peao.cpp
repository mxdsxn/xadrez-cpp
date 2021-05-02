#include "./Peao.h"
#include <iostream>

using namespace std;

Peao::Peao(string estilo, bool sentidoJogador1) : Peca(estilo, sentidoJogador1)
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
    bool sentidoJogador1 = this->sentidoJogador1;
    Posicao *posicaoAtualPeca = this->posicao;

    // Posicao a frente - 1 casa pra frente se estiver vazia
    xPosicao = posicaoAtualPeca->x;
    yPosicao = posicaoAtualPeca->y + (sentidoJogador1 ? 1 : -1);
    Posicao *posicaoFrente = (*posicoesTabuleiro)[yPosicao][xPosicao];

    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (posicaoFrente->pecaAtual == nullptr))
    {
      posicoesValidas.push_back(posicaoFrente);

      // Posicao a frente(primeira jogada) - 2 casa pra frente se estiver vazia
      if (this->primeiraJogada)
      {
        xPosicao = posicaoAtualPeca->x;
        yPosicao = posicaoAtualPeca->y + (sentidoJogador1 ? 2 : -2);
        Posicao *posicaoFrentePrimeiraJogada = (*posicoesTabuleiro)[yPosicao][xPosicao];

        if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (posicaoFrentePrimeiraJogada->pecaAtual == nullptr))
        {
          posicoesValidas.push_back(posicaoFrentePrimeiraJogada);
        }
      }
    }

    // Posicao a diagonal esquerda - 1 casa pra frente se estiver vazia
    xPosicao = posicaoAtualPeca->x + (sentidoJogador1 ? -1 : 1);
    yPosicao = posicaoAtualPeca->y + (sentidoJogador1 ? 1 : -1);
    Posicao *posicaoDiagonalEsquerda = (*posicoesTabuleiro)[yPosicao][xPosicao];

    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro) && (posicaoDiagonalEsquerda->pecaAtual != nullptr))
    {
      posicoesValidas.push_back(posicaoDiagonalEsquerda);
    }

    // Posicao a diagonal direita - 1 casa pra frente se estiver vazia
    xPosicao = posicaoAtualPeca->x + (sentidoJogador1 ? 1 : -1);
    yPosicao = posicaoAtualPeca->y + (sentidoJogador1 ? 1 : -1);
    Posicao *posicaoDiagonalDireita = (*posicoesTabuleiro)[yPosicao][xPosicao];

    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro) && (posicaoDiagonalDireita->pecaAtual != nullptr))
    {
      posicoesValidas.push_back(posicaoDiagonalDireita);
    }
  }

  return posicoesValidas;
}

bool Peao::movimentar(Posicao *novaPosicao)
{
  if (this)
  {
    Posicao *antigaPosicao = this->posicao;

    novaPosicao->pecaAtual->setPosicao(nullptr); // desvincula nova posicao da peca capturada
    antigaPosicao->setPeca(nullptr);             // desvincula peça movimentada da antiga posicao
    novaPosicao->setPeca(this);                  // vincula peca movimentada à nova posicao
    this->setPosicao(novaPosicao);               // vincula nova posicao à peca movimentada
    this->primeiraJogada = false;                // remove a flag de primeiraJogada do peao

    return true;
  }

  return false;
}

bool Peao::setPosicao(Posicao *novaPosicao)
{
  if (this)
  {
    this->posicao = novaPosicao;
    return true;
  }

  return false;
}
