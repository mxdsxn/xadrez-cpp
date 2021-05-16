#include "./Bispo.h"
#include <iostream>

using namespace std;

Bispo::Bispo(string estilo, bool sentidoPraFrente) : Peca(estilo, sentidoPraFrente)
{
  this->simbolo = this->estilo == "preto" ? "♗" : "♝";
  this->primeiraJogada = true;
  this->codigo = 4;
}
Bispo::~Bispo() {}

vector<Posicao *> Bispo::getTodasJogadasDisponiveis(vector<vector<Posicao *>> *posicoesTabuleiro)
{
  vector<Posicao *> posicoesValidas;
  if (this && this->posicao != nullptr)
  {
    int limiteTabuleiro = 8;
    int xPosicao, yPosicao;
    bool sentidoPraFrente = this->sentidoPraFrente;
    Posicao *posicaoAtualPeca = this->posicao;

    // Percorre posicoes na mesma direçao diagonal - direita/frente
    for (int indice = 1; indice < limiteTabuleiro; indice++)
    {
      yPosicao = posicaoAtualPeca->getY() + indice;
      xPosicao = posicaoAtualPeca->getX() + indice;

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
          break;
        }
      }
    }

    // Percorre posicoes na mesma direçao horizontal - esquerda/frente
    for (int indice = 1; indice < limiteTabuleiro; indice++)
    {
      yPosicao = posicaoAtualPeca->getY() + indice;
      xPosicao = posicaoAtualPeca->getX() - indice;

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
          break;
        }
      }
    }

    // Percorre posicoes na mesma direçao diagonal - direita/atras
    for (int indice = 1; indice < limiteTabuleiro; indice++)
    {
      yPosicao = posicaoAtualPeca->getY() - indice;
      xPosicao = posicaoAtualPeca->getX() + indice;

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
          break;
        }
      }
    }

    // Percorre posicoes na mesma direçao horizontal - esquerda/atras
    for (int indice = 1; indice < limiteTabuleiro; indice++)
    {
      yPosicao = posicaoAtualPeca->getY() - indice;
      xPosicao = posicaoAtualPeca->getX() - indice;

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
          break;
        }
      }
    }
  }

  return posicoesValidas;
}
