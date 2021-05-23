#pragma once

#include "../pecaBase/Peca.h"
using namespace std;

class Peao : public Peca
{
public:
  Peao(string estilo, bool sentidoPraFrente);
  Peao(int idPeca,
       bool emXeque,
       bool sentidoPraFrente,
       bool primeiraJogada,
       int coordenada_x,
       int coordenada_y);
  ~Peao();

  /**
   * @param posicoesTabuleiro Ponteiro para a matriz de posicoes do tabuleiro
   * @return Retorna lista de posições validas para o Peão, de acordo com sua regra de movimentação.
   */
  vector<Posicao *> getTodasJogadasDisponiveis(vector<vector<Posicao *>> *posicoesTabuleiro);
};
