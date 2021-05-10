#include "./Cavalo.h"
#include <iostream>

using namespace std;

Cavalo::Cavalo(string estilo, bool sentidoPraFrente) : Peca(estilo, sentidoPraFrente)
{
  this->simbolo = this->estilo == "preto" ? "♘" : "♞";
  this->primeiraJogada = true;
  this->codigo = 3;
}
Cavalo::~Cavalo() {}

vector<Posicao *> Cavalo::getTodasJogadasDisponiveis(vector<vector<Posicao *>> *posicoesTabuleiro)
{
  vector<Posicao *> posicoesValidas;
  if (this && this->posicao != nullptr)
  {
    int limiteTabuleiro = 8;
    int xPosicao, yPosicao;
    Posicao *posicaoAtualPeca = this->posicao;

    // Jogada frente/direita
    xPosicao = posicaoAtualPeca->getX() + 1;
    yPosicao = posicaoAtualPeca->getY() + 2;
    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro))
    {
      Posicao *posicaoPossivelJogada = (*posicoesTabuleiro)[yPosicao][xPosicao];
      Peca *pecaPosicaoPossivelJogada = posicaoPossivelJogada->getPecaAtual();

      if (pecaPosicaoPossivelJogada == nullptr)
      {
        posicoesValidas.push_back(posicaoPossivelJogada);
      }
      else
      {
        if (pecaPosicaoPossivelJogada->getEstilo() != this->estilo)
        {
          posicoesValidas.push_back(posicaoPossivelJogada);
        }
      }
    }

    // Jogada frente/esquerda
    xPosicao = posicaoAtualPeca->getX() - 1;
    yPosicao = posicaoAtualPeca->getY() + 2;
    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro))
    {
      Posicao *posicaoPossivelJogada = (*posicoesTabuleiro)[yPosicao][xPosicao];
      Peca *pecaPosicaoPossivelJogada = posicaoPossivelJogada->getPecaAtual();

      if (pecaPosicaoPossivelJogada == nullptr)
      {
        posicoesValidas.push_back(posicaoPossivelJogada);
      }
      else
      {
        if (pecaPosicaoPossivelJogada->getEstilo() != this->estilo)
        {
          posicoesValidas.push_back(posicaoPossivelJogada);
        }
      }
    }

    // Jogada atras/direita
    xPosicao = posicaoAtualPeca->getX() + 1;
    yPosicao = posicaoAtualPeca->getY() - 2;
    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro))
    {
      Posicao *posicaoPossivelJogada = (*posicoesTabuleiro)[yPosicao][xPosicao];
      Peca *pecaPosicaoPossivelJogada = posicaoPossivelJogada->getPecaAtual();

      if (pecaPosicaoPossivelJogada == nullptr)
      {
        posicoesValidas.push_back(posicaoPossivelJogada);
      }
      else
      {
        if (pecaPosicaoPossivelJogada->getEstilo() != this->estilo)
        {
          posicoesValidas.push_back(posicaoPossivelJogada);
        }
      }
    }

    // Jogada atras/esquerda
    xPosicao = posicaoAtualPeca->getX() - 1;
    yPosicao = posicaoAtualPeca->getY() - 2;
    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro))
    {
      Posicao *posicaoPossivelJogada = (*posicoesTabuleiro)[yPosicao][xPosicao];
      Peca *pecaPosicaoPossivelJogada = posicaoPossivelJogada->getPecaAtual();

      if (pecaPosicaoPossivelJogada == nullptr)
      {
        posicoesValidas.push_back(posicaoPossivelJogada);
      }
      else
      {
        if (pecaPosicaoPossivelJogada->getEstilo() != this->estilo)
        {
          posicoesValidas.push_back(posicaoPossivelJogada);
        }
      }
    }

    // Jogada direita/frente
    xPosicao = posicaoAtualPeca->getX() - 2;
    yPosicao = posicaoAtualPeca->getY() + 1;
    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro))
    {
      Posicao *posicaoPossivelJogada = (*posicoesTabuleiro)[yPosicao][xPosicao];
      Peca *pecaPosicaoPossivelJogada = posicaoPossivelJogada->getPecaAtual();

      if (pecaPosicaoPossivelJogada == nullptr)
      {
        posicoesValidas.push_back(posicaoPossivelJogada);
      }
      else
      {
        if (pecaPosicaoPossivelJogada->getEstilo() != this->estilo)
        {
          posicoesValidas.push_back(posicaoPossivelJogada);
        }
      }
    }

    // Jogada direita/atras
    xPosicao = posicaoAtualPeca->getX() - 2;
    yPosicao = posicaoAtualPeca->getY() - 1;
    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro))
    {
      Posicao *posicaoPossivelJogada = (*posicoesTabuleiro)[yPosicao][xPosicao];
      Peca *pecaPosicaoPossivelJogada = posicaoPossivelJogada->getPecaAtual();

      if (pecaPosicaoPossivelJogada == nullptr)
      {
        posicoesValidas.push_back(posicaoPossivelJogada);
      }
      else
      {
        if (pecaPosicaoPossivelJogada->getEstilo() != this->estilo)
        {
          posicoesValidas.push_back(posicaoPossivelJogada);
        }
      }
    }

    // Jogada esquerda/frente
    xPosicao = posicaoAtualPeca->getX() + 2;
    yPosicao = posicaoAtualPeca->getY() + 1;
    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro))
    {
      Posicao *posicaoPossivelJogada = (*posicoesTabuleiro)[yPosicao][xPosicao];
      Peca *pecaPosicaoPossivelJogada = posicaoPossivelJogada->getPecaAtual();

      if (pecaPosicaoPossivelJogada == nullptr)
      {
        posicoesValidas.push_back(posicaoPossivelJogada);
      }
      else
      {
        if (pecaPosicaoPossivelJogada->getEstilo() != this->estilo)
        {
          posicoesValidas.push_back(posicaoPossivelJogada);
        }
      }
    }

    // Jogada esquerda/atras
    xPosicao = posicaoAtualPeca->getX() + 2;
    yPosicao = posicaoAtualPeca->getY() - 1;
    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro))
    {
      Posicao *posicaoPossivelJogada = (*posicoesTabuleiro)[yPosicao][xPosicao];
      Peca *pecaPosicaoPossivelJogada = posicaoPossivelJogada->getPecaAtual();

      if (pecaPosicaoPossivelJogada == nullptr)
      {
        posicoesValidas.push_back(posicaoPossivelJogada);
      }
      else
      {
        if (pecaPosicaoPossivelJogada->getEstilo() != this->estilo)
        {
          posicoesValidas.push_back(posicaoPossivelJogada);
        }
      }
    }
  }

  return posicoesValidas;
}
