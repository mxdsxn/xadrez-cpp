#pragma once

#include "./Peca.h"
using namespace std;

class Rei : public Peca
{
public:
  Rei(string estilo, bool sentidoPraFrente);
  ~Rei();

  /**
   * @param posicoesTabuleiro Ponteiro para a matriz de posicoes do tabuleiro
   * @return Retorna lista de posições validas para o Rei, de acordo com sua regra de movimentação.
   */
  vector<Posicao *> getTodasJogadasDisponiveis(vector<vector<Posicao *>> *posicoesTabuleiro);

  /**
     * Usado para alterar o estado de xeque do Rei.
     * @param emXeque TRUE quando rei estiver em xeque.
     */
  void setXeque(bool emXeque);

private:
};
