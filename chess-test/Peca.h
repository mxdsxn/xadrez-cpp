#ifndef _PECA_H
#define _PECA_H

#include <string>
#include <vector>

using namespace std;

class Peca
{
public:
  string tipo;
  string estilo;
  string simbolo;

  Peca(string estilo);
  ~Peca();

  /**
   * @param novaPosicao Posição de destino para a peça.
   * @return Retorna 'true' se movimentou, false caso de algo errado.
   */
  virtual bool movimentar(int xPos, int yPos) = 0;

  /**
   * @return Retorna lista de posições validas para a peça, de acordo com sua regra de movimentação.
   */
  //virtual vector<Posicao *> getPosicoesValidas() = 0;

  /**
   * @param posicaoReiAdversario Posição de destino para a peça.
   * @return Retorna 'true' se movimentou, false caso de algo errado.
   */
  virtual bool verificaXequeAdversario(int xPos, int yPos) = 0;

protected:
  int codigo;
};

#endif //_PECA_H
