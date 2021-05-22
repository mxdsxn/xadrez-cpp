#include "./FabricaPartida.h"
#include "../partidaBase/Partida.h"
#include "../partidaTradicional/PartidaTradicional.h"

FabricaPartida::FabricaPartida() {}
FabricaPartida::~FabricaPartida() {}

Partida *FabricaPartida::novaPartida(int opcaoPartida, string nomePrimeiroJogador, string nomeSegundoJogador)
{
  Partida *novaPartida;
  switch (opcaoPartida)
  {
  case TipoPartida::Tradicional:
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

Partida *FabricaPartida::recuperaPartida(int idPartida, bool turnoPrimeiroJogador, int codigoTipo)
{
  Partida *novaPartida;
  switch (codigoTipo)
  {
  case TipoPartida::Tradicional:
    novaPartida = new PartidaTradicional(idPartida, turnoPrimeiroJogador, codigoTipo);
    break;
  case 2:
    novaPartida = new PartidaTradicional(idPartida, turnoPrimeiroJogador, codigoTipo);
    break;
  case 3:
    novaPartida = new PartidaTradicional(idPartida, turnoPrimeiroJogador, codigoTipo);
    break;
  }
  return novaPartida;
}
