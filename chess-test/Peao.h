#pragma once

#include "./Peca.h"
using namespace std;

class Peao : public Peca
{
public:
  Peao(string estilo, bool sentidoJogador1);
  ~Peao();

  /**
   * @return Retorna lista de posições validas para o Peão, de acordo com sua regra de movimentação.
   */
  vector<Posicao *> getPosicoesValidas(vector<vector<Posicao *>> *posicoesTabuleiro);
};
