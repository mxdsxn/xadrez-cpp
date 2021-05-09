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
  vector<Posicao *> getPosicoesValidas(vector<vector<Posicao *>> *posicoesTabuleiro);

  /**
     * @param emXeque TRUE quando a peca estiver em xeque.
     */
  void setXeque(bool emXeque);

private:
  /**
   * @param posicoesTabuleiro Ponteiro para a matriz de posicoes do tabuleiro
   * @return Retorna TRUE quando a jogada irá colocar o Rei em Xeque.
   */
  bool validaJogadaXeque(vector<vector<Posicao *>> *posicoesTabuleiro, Posicao *jogadaPretendida);
};
