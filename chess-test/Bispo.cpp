#include "./Bispo.h"
#include <iostream>
#include "./utils.h"

using namespace std;

Bispo::Bispo(string estilo, bool sentidoPraFrente) : Peca(estilo, sentidoPraFrente)
{
  this->simbolo = this->estilo == "preto" ? "♗" : "♝";
  this->primeiraJogada = true;
  this->codigo = 1;
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

    yPosicao = posicaoAtualPeca->getY();
    // Percorre posicoes na mesma direçao horizontal - direita
    for (int indice = 1; indice < limiteTabuleiro; indice++)
    {
      xPosicao = posicaoAtualPeca->getX() + indice;

      if ((xPosicao >= 0 && xPosicao < limiteTabuleiro))
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

    // Percorre posicoes na mesma direçao horizontal - esquerda
    for (int indice = 1; indice < limiteTabuleiro; indice++)
    {
      xPosicao = posicaoAtualPeca->getX() - indice;

      if ((xPosicao >= 0 && xPosicao < limiteTabuleiro))
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

    xPosicao = posicaoAtualPeca->getX();
    // Percorre posicoes na mesma direçao vertical - frente
    for (int indice = 1; indice < limiteTabuleiro; indice++)
    {
      yPosicao = posicaoAtualPeca->getY() + indice;

      if ((yPosicao >= 0 && yPosicao < limiteTabuleiro))
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

    // Percorre posicoes na mesma direçao vertical - atras
    for (int indice = 1; indice < limiteTabuleiro; indice++)
    {
      yPosicao = posicaoAtualPeca->getY() - indice;

      if ((yPosicao >= 0 && yPosicao < limiteTabuleiro))
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
