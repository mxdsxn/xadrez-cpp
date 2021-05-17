#pragma once

#include "../../tabuleiro/Tabuleiro.h"
#include "../../jogador/Jogador.h"
#include "../partidaDTO/PartidaDTO.h"

class PartidaDTO;
class Partida
{
protected:
  bool turnoPrimeiroJogador;
  Tabuleiro *tabuleiro;
  PartidaDTO *partidaDTO;
  Jogador *primeiroJogador;
  Jogador *segundoJogador;

public:
  Partida();
  virtual void iniciarPartida() = 0;
  virtual void salvarPartida() = 0;
  virtual void encerrarPartida() = 0;
  bool getTurnoPrimeiroJogador();
  Tabuleiro *getTabuleiro();
  Jogador *getPrimeiroJogador();
  Jogador *getSegundoJogador();
};
