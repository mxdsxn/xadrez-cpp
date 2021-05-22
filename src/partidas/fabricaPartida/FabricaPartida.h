#pragma once
#include "../partidaBase/Partida.h"

class Partida;
class FabricaPartida
{
public:
  FabricaPartida();
  ~FabricaPartida();

  Partida *novaPartida(int opcaoPartida, string nomePrimeiroJogador, string nomeSegundoJogador);
  Partida *recuperaPartida(int idPartida, bool turnoPrimeiroJogador, int codigoTipo);
};
