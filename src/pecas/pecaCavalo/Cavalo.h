#pragma once

#include "../pecaBase/Peca.h"
using namespace std;

class Cavalo : public Peca
{
public:
  Cavalo(string estilo, bool sentidoPraFrente);
  Cavalo(int idPeca,
         bool emXeque,
         bool sentidoPraFrente,
         bool primeiraJogada,
         int coordenada_x,
         int coordenada_y);
  ~Cavalo();

  /**
   * @param posicoesTabuleiro Ponteiro para a matriz de posicoes do tabuleiro
   * @return Retorna lista de posições validas para o Cavalo, de acordo com sua regra de movimentação.
   */
  vector<Posicao *> getTodasJogadasDisponiveis(vector<vector<Posicao *>> *posicoesTabuleiro);
};
