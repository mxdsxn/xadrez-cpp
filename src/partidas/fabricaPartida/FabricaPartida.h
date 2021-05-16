#pragma once
#include "../partidaBase/Partida.h"

class FabricaPartida
{
public:
  FabricaPartida();
  ~FabricaPartida();

  Partida *novaPartida(int opcaoPartida, string nomePrimeiroJogador, string nomeSegundoJogador);
};
