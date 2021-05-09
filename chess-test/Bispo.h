#pragma once

#include "./Peca.h"
using namespace std;

class Bispo : public Peca
{
public:
  Bispo(string estilo, bool sentidoPraFrente);
  ~Bispo();

  /**
   * @param posicoesTabuleiro Ponteiro para a matriz de posicoes do tabuleiro
   * @return Retorna lista de posições validas para o Bispo, de acordo com sua regra de movimentação.
   */
  vector<Posicao *> getTodasJogadasDisponiveis(vector<vector<Posicao *>> *posicoesTabuleiro);
};
