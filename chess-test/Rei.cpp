#include "./Rei.h"
#include <iostream>

using namespace std;

Rei::Rei(string estilo, bool sentidoPraFrente) : Peca(estilo, sentidoPraFrente)
{
  this->simbolo = this->estilo == "preto" ? "♔" : "♚";
  this->primeiraJogada = true;
  this->codigo = 1;
}
Rei::~Rei() {}

vector<Posicao *> Rei::getTodasJogadasDisponiveis(vector<vector<Posicao *>> *posicoesTabuleiro)
{
  vector<Posicao *> posicoesValidas;
  if (this && this->posicao != nullptr)
  {
    int limiteTabuleiro = 8;
    int xPosicao, yPosicao;
    bool sentidoPraFrente = this->sentidoPraFrente;
    Posicao *posicaoAtualPeca = this->posicao;

    // Percorre linha da frente analisando possiblidades
    yPosicao = posicaoAtualPeca->getY() + (sentidoPraFrente ? 1 : -1);
    for (int indice = -1; indice <= 1; indice++)
    {
      xPosicao = posicaoAtualPeca->getX() + indice;
      if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro))
      {
        Posicao *posicaoPossivelJogada = (*posicoesTabuleiro)[yPosicao][xPosicao];
        Peca *pecaPosicaoPossivelJogada = posicaoPossivelJogada->getPecaAtual();

        if ((pecaPosicaoPossivelJogada->getEstilo() != this->estilo) || (pecaPosicaoPossivelJogada == nullptr))
        {
          posicoesValidas.push_back(posicaoPossivelJogada);
        }
      }
    }

    // Percorre linha de tras analisando possiblidades
    yPosicao = posicaoAtualPeca->getY() + (sentidoPraFrente ? -1 : 1);
    for (int indice = -1; indice <= 1; indice++)
    {
      xPosicao = posicaoAtualPeca->getX() + indice;
      if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro))
      {
        Posicao *posicaoPossivelJogada = (*posicoesTabuleiro)[yPosicao][xPosicao];
        Peca *pecaPosicaoPossivelJogada = posicaoPossivelJogada->getPecaAtual();

        if ((pecaPosicaoPossivelJogada->getEstilo() != this->estilo) || (pecaPosicaoPossivelJogada == nullptr))
        {
          posicoesValidas.push_back(posicaoPossivelJogada);
        }
      }
    }

    // Percorre linha de tras analisando possiblidades
    yPosicao = posicaoAtualPeca->getY();

    xPosicao = posicaoAtualPeca->getX() + 1;
    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro))
    {
      Posicao *posicaoPossivelJogada = (*posicoesTabuleiro)[yPosicao][xPosicao];
      Peca *pecaPosicaoPossivelJogada = posicaoPossivelJogada->getPecaAtual();

      if ((pecaPosicaoPossivelJogada->getEstilo() != this->estilo) || (pecaPosicaoPossivelJogada == nullptr))
      {
        posicoesValidas.push_back(posicaoPossivelJogada);
      }
    }

    xPosicao = posicaoAtualPeca->getX() - 1;
    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro))
    {
      Posicao *posicaoPossivelJogada = (*posicoesTabuleiro)[yPosicao][xPosicao];
      Peca *pecaPosicaoPossivelJogada = posicaoPossivelJogada->getPecaAtual();

      if ((pecaPosicaoPossivelJogada->getEstilo() != this->estilo) || (pecaPosicaoPossivelJogada == nullptr))
      {
        posicoesValidas.push_back(posicaoPossivelJogada);
      }
    }
  }

  return posicoesValidas;
}

void Rei::setXeque(bool emXeque)
{
  if (this)
  {
    this->emXeque = emXeque;
  }
}
