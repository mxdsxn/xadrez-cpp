#include "Posicao.h"

Posicao::Posicao(int x, int y)
{
  this->x = x;
  this->y = y;
  this->pecaAtual = nullptr;
}

Posicao::~Posicao() {}

string Posicao::showSimbolo()
{
  if (this)
  {
    return this->pecaAtual != nullptr ? this->pecaAtual->simbolo : "";
  }
  return "";
}

bool Posicao::setPeca(Peca *novaPeca)
{
  if (this)
  {
    this->pecaAtual = novaPeca;
    novaPeca->posicao = this;
    return true;
  }

  return false;
}

bool Posicao::removePeca()
{
  if (this)
  {
    this->pecaAtual = nullptr;
    return true;
  }

  return false;
}
