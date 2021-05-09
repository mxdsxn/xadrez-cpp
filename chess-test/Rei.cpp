#include "./Rei.h"
#include <iostream>
#include "./utils.h"

using namespace std;

Rei::Rei(string estilo, bool sentidoPraFrente) : Peca(estilo, sentidoPraFrente)
{
  this->simbolo = this->estilo == "preto" ? "♔" : "♚";
  this->primeiraJogada = true;
  this->codigo = 1;
}
Rei::~Rei() {}

bool Rei::validaJogadaXeque(vector<vector<Posicao *>> *posicoesTabuleiro, Posicao *jogadaPretendida)
{
  if (this)
  {
    vector<Posicao *> jogadasDisponiveisTodasPecas;

    for (int y = 0; y < 8; y++)
    {
      for (int x = 0; x < 8; x++)
      {
        Posicao *posicaoAtual = (*posicoesTabuleiro)[y][x];
        Peca *pecaAtual = posicaoAtual->getPecaAtual();

        if (pecaAtual != nullptr && pecaAtual->getEstilo() != this->estilo && this->getCodigo() != pecaAtual->getCodigo())
        {
          bool possibilidadeXeque = pecaAtual->verificaXequeAdversario(jogadaPretendida, posicoesTabuleiro);

          if (possibilidadeXeque)
          {
            return possibilidadeXeque;
          }
        }
      }
    }
  }
  return false;
}

vector<Posicao *> Rei::getPosicoesValidas(vector<vector<Posicao *>> *posicoesTabuleiro)
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
          if (!validaJogadaXeque(posicoesTabuleiro, posicaoPossivelJogada))
          {
            posicoesValidas.push_back(posicaoPossivelJogada);
          }
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
          if (!validaJogadaXeque(posicoesTabuleiro, posicaoPossivelJogada))
          {
            posicoesValidas.push_back(posicaoPossivelJogada);
          }
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
        if (!validaJogadaXeque(posicoesTabuleiro, posicaoPossivelJogada))
        {
          posicoesValidas.push_back(posicaoPossivelJogada);
        }
      }
    }

    xPosicao = posicaoAtualPeca->getX() - 1;
    if ((yPosicao >= 0 && yPosicao < limiteTabuleiro) && (xPosicao >= 0 && xPosicao < limiteTabuleiro))
    {
      Posicao *posicaoPossivelJogada = (*posicoesTabuleiro)[yPosicao][xPosicao];
      Peca *pecaPosicaoPossivelJogada = posicaoPossivelJogada->getPecaAtual();

      if ((pecaPosicaoPossivelJogada->getEstilo() != this->estilo) || (pecaPosicaoPossivelJogada == nullptr))
      {
        if (!validaJogadaXeque(posicoesTabuleiro, posicaoPossivelJogada))
        {
          posicoesValidas.push_back(posicaoPossivelJogada);
        }
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
