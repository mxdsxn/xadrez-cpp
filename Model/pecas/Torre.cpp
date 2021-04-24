#include "Torre.h"

Torre::Torre(string estilo, Posicao *posicao = nullptr, Tabuleiro *tabuleiro) : Peca(estilo)
{
  this->simbolo = this->estilo == "black" ? "♜" : "♖";
  this->posicao = posicao;
  this->tabuleiro = tabuleiro;
}
Torre::~Torre() {}

vector<Posicao *> Torre::getPosicoesValidas()
{
  vector<Posicao *> posicoesValidas;

  return posicoesValidas;
}