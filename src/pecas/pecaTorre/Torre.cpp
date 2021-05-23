#include "./Torre.h"
#include <iostream>

using namespace std;

Torre::Torre(string estilo, bool sentidoPraFrente) : Peca(estilo, sentidoPraFrente)
{
  this->codigo = 5;
  this->simbolo = this->estilo == "preto" ? "♖" : "♜";
  this->primeiraJogada = true;
}

Torre::Torre(int idPeca, bool emXeque, bool sentidoPraFrente, bool primeiraJogada, int coordenada_x, int coordenada_y) : Peca(sentidoPraFrente ? "branco" : "preto", sentidoPraFrente)
{
  this->codigo = 5;
  this->simbolo = this->estilo == "preto" ? "♖" : "♜";
  this->emXeque = emXeque;
  this->sentidoPraFrente = sentidoPraFrente;
  this->primeiraJogada = primeiraJogada;
  this->sql_idPeca = sql_idPeca;
  this->posicao = new Posicao(coordenada_x, coordenada_y, false);
}

Torre::~Torre() {}

vector<Posicao *> Torre::getTodasJogadasDisponiveis(vector<vector<Posicao *>> *posicoesTabuleiro)
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
