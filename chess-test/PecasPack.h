#pragma once

#include "./Peca.h"
#include "./Posicao.h"

class Peca;

class PecasPack
{

private:
  string estilo;

  vector<Peca *> peoes;

public:
  PecasPack(string estilo, bool sentidoPraFrente);
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
