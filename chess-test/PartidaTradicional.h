#pragma once

#include "./Partida.h"
#include "./Jogador.h"

class PartidaTradicional : public Partida
{
private:
  Jogador *primeiroJogador;
  Jogador *segundoJogador;
  bool turnoPrimeiroJogador;

  void mostrarTabuleiro(bool turnoPrimeiroJogador);
  Peca *selecionarPecaDisponivel(bool primeiroJogador);

public:
  PartidaTradicional(string nomePrimeiroJogador, string nomeSegundoJogador);
  void iniciarPartida();
  void salvarPartida();
  void encerrarPartida();
};
