#pragma once

#include "../../tabuleiro/Tabuleiro.h"
#include "../../jogador/Jogador.h"
#include "../partidaDAO/PartidaDAO.h"

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
  int sql_idPartida;

public:
  Partida();
  Partida(int idPartida, bool turnoPrimeiroJogador);
  ~Partida();
  virtual void iniciarPartida() = 0;
  virtual void salvarPartida() = 0;
  virtual void encerrarPartida() = 0;
  bool getTurnoPrimeiroJogador();
  Tabuleiro *getTabuleiro();
  Jogador *getPrimeiroJogador();
  Jogador *getSegundoJogador();
  int getCodigoTipo();
  int getSqlIdPartida();
};
