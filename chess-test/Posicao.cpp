#include "./Posicao.h"
#include <iostream>

using namespace std;

Posicao::Posicao(int x, int y)
{
  this->x = x;
  this->y = y;
  this->pecaAtual = nullptr;
}

Posicao::~Posicao() {}

string Posicao::show()
{
  string simbolo = "X";

  if (this)
  {
    simbolo = this->pecaAtual != nullptr ? this->pecaAtual->simbolo : " ";
  }

  return "[" + simbolo + "]";
}

string Posicao::showSimbolo()
{
  if (this)
  {
    return this->pecaAtual != nullptr ? this->pecaAtual->simbolo : "X";
  }

  return "";
}

bool Posicao::setPeca(Peca *novaPeca)
{
  if (this)
  {
    this->pecaAtual = novaPeca;
    //novaPeca->posicao = this;
    return true;
  }

  return false;
}

bool Posicao::removePeca()
{
  cout << "[POSICAO] - Metodo `removePeca()" << endl;
  if (this)
  {
    //this->pecaAtual->posicao = nullptr;
    this->pecaAtual = nullptr;
    return true;
  }

  return false;
}
