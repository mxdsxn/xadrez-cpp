#include "./FabricaPartida.h"
#include "./PartidaTradicional.h"

FabricaPartida::FabricaPartida() {}
FabricaPartida::~FabricaPartida() {}

Partida *FabricaPartida::novaPartida(int opcaoPartida, string nomePrimeiroJogador, string nomeSegundoJogador)
{
  Partida *novaPartida;
  switch (opcaoPartida)
  {
  case 1:
    novaPartida = new PartidaTradicional(nomePrimeiroJogador, nomeSegundoJogador);
    break;
  case 2:
    novaPartida = new PartidaTradicional(nomePrimeiroJogador, nomeSegundoJogador);
    break;
  case 3:
    novaPartida = new PartidaTradicional(nomePrimeiroJogador, nomeSegundoJogador);
    break;
  }
  return novaPartida;
}
