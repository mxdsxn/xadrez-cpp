#ifndef _PECA_H
#define _PECA_H

#include <string>
#include <vector>
#include "./Posicao.h"

using namespace std;

class Posicao;

class Peca
{
public:
  //string tipo;

  string simbolo;
  string estilo;
  Posicao *posicao;

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
  //virtual vector<Posicao *> getPosicoesValidas() = 0;

  /**
   * @param posicaoReiAdversario Posição de destino para a peça.
   * @return Retorna 'true' se movimentou, false caso de algo errado.
   */
  virtual bool verificaXequeAdversario(int xPos, int yPos) = 0;

  /**
   * @param novaPosicao Posição de destino para a peça.
   * @return Retorna 'true' se inseriu corretamente a posicao, false caso de algo errado.
   */
  virtual bool setPosicao(Posicao *novaPosicao) = 0;

protected:
  int codigo;
};

#endif //_PECA_H
