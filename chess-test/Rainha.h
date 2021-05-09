#pragma once

#include "./Peca.h"
using namespace std;

class Rainha : public Peca
{
public:
  Rainha(string estilo, bool sentidoPraFrente);
  ~Rainha();

  /**
   * @param posicoesTabuleiro Ponteiro para a matriz de posicoes do tabuleiro
   * @return Retorna lista de posições validas para a Rainha, de acordo com sua regra de movimentação.
   */
  vector<Posicao *> getTodasJogadasDisponiveis(vector<vector<Posicao *>> *posicoesTabuleiro);
};
