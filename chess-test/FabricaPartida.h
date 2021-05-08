#pragma once
#include "./Partida.h"

class FabricaPartida
{
public:
  FabricaPartida();
  ~FabricaPartida();

  Partida *novaPartida(int opcaoPartida, string nomePrimeiroJogador, string nomeSegundoJogador);
};
