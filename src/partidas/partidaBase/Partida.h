#pragma once

#include "../../tabuleiro/Tabuleiro.h"
#include "../../jogador/Jogador.h"

enum TipoPartida
{
  Tradicional = 1
};

class PartidaDAO;
class Partida
{
protected:
  bool turnoPrimeiroJogador;
  Tabuleiro *tabuleiro;
  PartidaDAO *partidaDAO;
  Jogador *primeiroJogador;
  Jogador *segundoJogador;
  int codigoTipo;

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
