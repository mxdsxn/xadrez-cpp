#pragma once

#include "../../tabuleiro/Tabuleiro.h"

class Partida
{
protected:
  Tabuleiro *tabuleiro;
  //Jogador *primeiroJogador;
  //Jogador *segundoJogador;

public:
  Partida();
  virtual void iniciarPartida() = 0;
  virtual void salvarPartida() = 0;
  virtual void encerrarPartida() = 0;
};
