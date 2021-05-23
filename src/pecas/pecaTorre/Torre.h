#pragma once

#include "../pecaBase/Peca.h"
using namespace std;

class Torre : public Peca
{
public:
  Torre(string estilo, bool sentidoPraFrente);
  Torre(int idPeca,
        bool emXeque,
        bool sentidoPraFrente,
        bool primeiraJogada,
        int coordenada_x,
        int coordenada_y);
  ~Torre();

  /**
   * @param posicoesTabuleiro Ponteiro para a matriz de posicoes do tabuleiro
   * @return Retorna lista de posições validas para a Torre, de acordo com sua regra de movimentação.
   */
  vector<Posicao *> getTodasJogadasDisponiveis(vector<vector<Posicao *>> *posicoesTabuleiro);
};
