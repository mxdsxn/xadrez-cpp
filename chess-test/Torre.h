#pragma once

#include "./Peca.h"
using namespace std;

class Torre : public Peca
{
public:
  Torre(string estilo, bool sentidoPraFrente);
  ~Torre();

  /**
   * @param posicoesTabuleiro Ponteiro para a matriz de posicoes do tabuleiro
   * @return Retorna lista de posições validas para a Torre, de acordo com sua regra de movimentação.
   */
  vector<Posicao *> getTodasJogadasDisponiveis(vector<vector<Posicao *>> *posicoesTabuleiro);
};
