#include "./Partida.h"

Partida::Partida()
{
  this->tabuleiro = new Tabuleiro();
  //this->partidaDAO = new PartidaDAO();
}

bool Partida::getTurnoPrimeiroJogador()
{
  if (this)
  {
    return this->turnoPrimeiroJogador;
  }
  return false;
}

Tabuleiro *Partida::getTabuleiro()
{
  if (this)
  {
    return this->tabuleiro;
  }
  return nullptr;
}

Jogador *Partida::getPrimeiroJogador()
{
  if (this)
  {
    return this->primeiroJogador;
  }
  return nullptr;
}

Jogador *Partida::getSegundoJogador()
{
  if (this)
  {
    return this->segundoJogador;
  }
  return nullptr;
}

int Partida::getCodigoTipo()
{
  if (this)
  {
    return this->codigoTipo;
  }
  return 0;
}
