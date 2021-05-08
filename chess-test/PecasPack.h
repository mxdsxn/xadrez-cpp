#pragma once

#include "./Peca.h"
#include "./Posicao.h"

class Peca;

class PecasPack
{
private:
  string estilo;
  vector<Peca *> peoes;
  Peca *rei;

public:
  PecasPack(string estilo, bool sentidoPraFrente);
  ~PecasPack();

  /**
   * @return Lista de posicoes com as peças pecasDisponiveis
   */
  vector<Peca *> getPecasDisponiveis();

  /**
     * @return Retorna `branco` ou `preto`.
     */
  string getEstilo();

  /**
     * @return Retorna posição atual do rei.
     */
  Posicao *getPosicaoRei();

  /**
     * Setta posicoes inciais para os peoes.
     * @param linhaInicialPeoes Linha inicial dos Peoes no tabuleiro .
     */
  void setPosicaoIncialPeoes(vector<Posicao *> *linhaInicialPeoes);
};
