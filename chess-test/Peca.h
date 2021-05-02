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

  Peca(string estilo, bool sentidoJogador1);
  ~Peca();

  /**
   * @return Retorna lista de posições validas para a peça, de acordo com sua regra de movimentação.
   */
  virtual vector<Posicao *> getPosicoesValidas(vector<vector<Posicao *>> *posicoesTabuleiro) = 0;

  /**
   * @param novaPosicao Posição de destino para a peça.
   * @return Retorna 'true' se movimentou, false caso de algo errado.
   */
  bool movimentar(Posicao *novaPosicao);

  /**
   * @param posicaoReiAdversario Posição de destino para a peça.
   * @return Retorna 'true' se movimentou, false caso de algo errado.
   */
  bool verificaXequeAdversario(Posicao *posicaoReiAdversario, vector<vector<Posicao *>> *posicoesTabuleiro);

  /**
   * @param novaPosicao Posição de destino para a peça.
   * @return Retorna 'true' se inseriu corretamente a posicao, false caso de algo errado.
   */
  bool setPosicao(Posicao *novaPosicao);

  /**
   * @param novaPosicao Posição de destino para a peça.
   * @return Retorna 'true' se inseriu corretamente a posicao, false caso de algo errado.
   */
  bool removePosicao();

protected:
  bool sentidoJogador1;
  bool primeiraJogada;
};

#endif //_PECA_H
