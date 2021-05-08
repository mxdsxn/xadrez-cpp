#include "./FabricaPartida.h"
#include "./PartidaTradicional.h"

FabricaPartida::FabricaPartida() {}
FabricaPartida::~FabricaPartida() {}

Partida *FabricaPartida::novaPartida(int opcaoPartida)
{
  Partida *novaPartida;
  switch (opcaoPartida)
  {
  case 1:
    novaPartida = new PartidaTradicional();
    break;
  case 2:
    novaPartida = new PartidaTradicional();
    break;
  case 3:
    novaPartida = new PartidaTradicional();
    break;
  }
  return novaPartida;
}
