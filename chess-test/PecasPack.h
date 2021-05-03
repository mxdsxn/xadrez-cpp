#pragma once

#include "./Peao.h"
#include "./Posicao.h"

class Peca;

class PecasPack
{

private:
  bool sentidoJogador1;
  string estilo;
  vector<Peao *> peoes;

public:
  PecasPack(string estilo, bool sentidoJogador1);
  ~PecasPack();

  //vector<Peca *> getPecasDisponiveis();

  /**
     * @return Retorna `branco` ou `preto`.
     */
  string getEstilo();

  /**
     * Setta posicoes inciais para os peoes.
     * @param linhaInicialPeoes Linha inicial dos Peoes no tabuleiro .
     */
  void setPosicaoIncialPeoes(vector<Posicao *> *linhaInicialPeoes);
};
