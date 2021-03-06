#pragma once

#include "../partidaBase/Partida.h"

class PartidaTradicional : public Partida
{
private:
  /**
    * Mostra ao usuario o tabuleiro
    * @param turnoPrimeiroJogador Booleano que quando TRUE, mostra o tabuleiro orientado para o primeiroJogador, FALSE, orientado ao segundoJogador
  */
  void mostrarTabuleiro(bool turnoPrimeiroJogador);

  /**
    * Mostra ao usuario as peças disponiveis no turno atual
    * @param primeiroJogador Booleano que quando TRUE, corresponde ao primeiroJogador, FALSE, ao segundoJogador
    * @return Peça selecionada para a jogada no turno atual
  */
  Peca *selecionarPecaDisponivel(bool primeiroJogador);

  /**
    * Mostra ao usuario as jogadas disponiveis para a peça selecionada
    * @param pecaSelecionada Peca selecionada pelo jogador
    * @return Booleano quando a jogada ocorre de maneira correta
  */
  bool selecionarJogadasDisponiveis(Peca *pecaSelecionada);

public:
  PartidaTradicional(string nomePrimeiroJogador, string nomeSegundoJogador);
  PartidaTradicional(int idPartida, bool turnoPrimeiroJogador, int codigoTipo);

  /**
    * Inicia o jogo - gerencia os turnos da partida
  */
  void iniciarPartida();
  void salvarPartida();
  void encerrarPartida();
};
