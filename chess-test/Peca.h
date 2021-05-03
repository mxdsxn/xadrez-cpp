#ifndef _PECA_H
#define _PECA_H

#include <string>
#include <vector>
#include "./Posicao.h"

using namespace std;

class Posicao;

class Peca
{
protected:
  bool sentidoPraFrente;
  bool primeiraJogada;
  string estilo;
  string simbolo;

public:
  Posicao *posicao;

  Peca(string estilo, bool sentidoPraFrente);
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

  /**
   * @return Poteiro da posicao atual da peca.
   */
  Posicao *getPosicaoAtual();

  /**
     * @return Retorna `branco` ou `preto`.
     */
  string getEstilo();

  /**
     * @return Retorna simbolo da peça.
     */
  string getSimbolo();

  /**
     * @return Retorna `true` quando as peças desse pacote andam pra frente.
     */
  bool getSentidoPraFrente();
};

#endif //_PECA_H
