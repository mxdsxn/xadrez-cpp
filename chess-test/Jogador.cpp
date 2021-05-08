#include "./Jogador.h"

Jogador::Jogador(string nome, PecasPack *pecas)
{
  this->nome = nome;
  this->pecas = pecas;
}

string Jogador::getNome()
{
  string nome;
  if (this)
  {
    nome = this->nome;
  }
  return nome;
}

PecasPack *Jogador::getPecas()
{
  PecasPack *pecas;
  if (this)
  {
    pecas = this->pecas;
  }
  return pecas;
}

Posicao *Jogador::getPosicaoRei()
{
  if (this)
  {
    return this->pecas->getPosicaoRei();
  }
  return nullptr;
}
