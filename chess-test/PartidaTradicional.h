#pragma once

#include "./Partida.h"
#include "./Jogador.h"

class PartidaTradicional : public Partida
{
private:
  Jogador *primeiroJogador;
  Jogador *segundoJogador;
  bool turnoPrimeiroJogador;

  /**
    * Mostra ao usuario o tabuleiro ao usuario
    * @param turnoPrimeiroJogador Booleano que quando TRUE, mostra o tabuleiro orientado para o primeiroJogador, FALSE, orientado ao segundoJogador
  */
  void mostrarTabuleiro(bool turnoPrimeiroJogador);

  /**
    * Mostra ao usuario as peças disponiveis no turno atual
    * @param primeiroJogador Booleano que quando TRUE, corresponde ao primeiroJogador, FALSE, ao segundoJogador
    * @return Peça selecionada para a jogada no turno atual
  */
  Peca *selecionarPecaDisponivel(bool primeiroJogador);

public:
  PartidaTradicional(string nomePrimeiroJogador, string nomeSegundoJogador);

  /**
    * Inicia o jogo - gerencia os turnos da partida
  */
  void iniciarPartida();
  void salvarPartida();
  void encerrarPartida();
};
