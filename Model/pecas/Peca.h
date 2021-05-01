#ifndef _PECA_H
#define _PECA_H

#include <string>
#include <vector>
#include "../tabuleiro/Posicao.h"
#include "../tabuleiro/Tabuleiro.h"

using namespace std;

class Tabuleiro;

class Peca
{
public:
  string tipo;
  Posicao *posicao;
  string estilo;
  Tabuleiro *tabuleiro;
  string simbolo;

  Peca(string estilo);
  ~Peca();

  /**
   * @param novaPosicao Posição de destino para a peça.
   * @return Retorna 'true' se movimentou, false caso de algo errado.
   */
  virtual bool movimentar(Posicao *novaPosicao) = 0;

  /**
   * @return Retorna lista de posições validas para a peça, de acordo com sua regra de movimentação.
   */
  virtual vector<Posicao *> getPosicoesValidas() = 0;

  /**
   * @param posicaoReiAdversario Posição de destino para a peça.
   * @return Retorna 'true' se movimentou, false caso de algo errado.
   */
  virtual bool verificaXequeAdversario(Posicao *posicaoReiAdversario) = 0;

protected:
  int codigo;
};

#endif //_PECA_H
