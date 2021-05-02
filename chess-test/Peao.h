#pragma once

#include "./Peca.h"
using namespace std;

class Peao : public Peca
{
public:
  Peao(string estilo, bool sentidoJogador1);
  ~Peao();

  /**
   * @return Retorna lista de posições validas para o Peão, de acordo com sua regra de movimentação.
   */
  vector<Posicao *> getPosicoesValidas(vector<vector<Posicao *>> &posicoesTabuleiro);

  /**
   * @param novaPosicao Nova posição para o Peão
   * @return Retorna 'true' quando o Peão foi movimentado com sucesso
   */
  bool movimentar(Posicao *novaPosicao);

  /**
   * @param posicaoReiAdversario Posição do Rei adversario
   * @return Retorna 'true' quando o Peão coloca o Rei adversario em xeque
   */
  bool verificaXequeAdversario(int xPosReiAdversario, int yPosReiAdversario);

  /**
   * @param novaPosicao Posição de destino para Peao.
   * @return Retorna 'true' se inseriu corretamente a posicao, false caso de algo errado.
   */
  virtual bool setPosicao(Posicao *novaPosicao);

private:
  bool primeiraJogada;
};
