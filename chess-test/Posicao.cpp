#include "./Posicao.h"
#include <iostream>

using namespace std;

Posicao::Posicao(int x, int y, bool posicaoPreta)
{
  this->x = x;
  this->y = y;
  this->pecaAtual = nullptr;
  this->posicaoPreta = posicaoPreta;
  this->simbolo = posicaoPreta ? "◻" : "◼";
}

Posicao::~Posicao() {}

string Posicao::showPosicao()
{
  string simbolo = " ";

  if (this)
  {
    simbolo = this->getPecaAtual() != nullptr ? this->showSimbolo() : this->simbolo;
  }

  return simbolo;
}

string Posicao::showSimbolo()
{
  if (this)
  {
    return this->getPecaAtual() != nullptr ? this->getPecaAtual()->getSimbolo() : "X";
  }

  return "";
}

bool Posicao::setPeca(Peca *novaPeca)
{
  if (this)
  {
    this->pecaAtual = novaPeca;
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

Peca *Posicao::getPecaAtual()
{
  if (this)
  {
    return this->pecaAtual;
  }
  return nullptr;
}

int Posicao::getX()
{
  if (this)
  {
    return this->x;
  }
  return -1;
}

int Posicao::getY()
{
  if (this)
  {
    return this->y;
  }
  return -1;
}
