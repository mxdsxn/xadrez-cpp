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
  bool emXeque;
  int codigo;

public:
  Posicao *posicao;

  Peca(string estilo, bool sentidoPraFrente);
  ~Peca();

  /**
     * @return retorna TRUE caso a peca esteja em Xeque.
     */
  bool getXeque();

  /**
     * @return inteiro representante do seu tipo de peça
     */
  int getCodigo();

  /**
     * @return Retorna `branco` ou `preto`.
     */
  string getEstilo();

  /**
     * @return Retorna simbolo da peça.
     */
  string getSimbolo();

  /**
   * @return Poteiro da posicao atual da peca.
   */
  Posicao *getPosicaoAtual();

  /**
   * @param posicoesTabuleiro Matriz de posicoes do tabuleiro.
   * @return Retorna lista de posições validas para a peça, de acordo com sua regra de movimentação.
   */
  virtual vector<Posicao *> getTodasJogadasDisponiveis(vector<vector<Posicao *>> *posicoesTabuleiro) = 0;

  /**
     * @return Retorna `true` quando as peças desse pacote andam pra frente.
     */
  bool getSentidoPraFrente();

  /**
     * @param emXeque boolean - nenhuma peça pode ser colocada em xeque por padrao.
     */
  virtual void setXeque(bool emXeque);

  /**
   * @param novaPosicao Posição de destino para a peça.
   * @return Retorna 'true' se inseriu corretamente a posicao, false caso de algo errado.
   */
  bool setPosicao(Posicao *novaPosicao);

  /**
   * @param novaPosicao Posição de destino para a peça.
   * @return Retorna 'true' se movimentou, false caso de algo errado.
   */
  bool movimentar(Posicao *novaPosicao, bool simulacao = false);

  /**
   * @param novaPosicao Posição de destino para a peça.
   * @return Retorna 'true' se inseriu corretamente a posicao, false caso de algo errado.
   */
  bool removePosicao();

  /**
   * @param posicaoReiAdversario Posição de destino para a peça.
   * @param posicoesTabuleiro Matriz de posicoes do tabuleiro.
   * @return Retorna 'true' se movimentou, false caso de algo errado.
   */
  bool verificaReiAdversarioXeque(Posicao *posicaoReiAdversario, vector<vector<Posicao *>> *posicoesTabuleiro);

  /**
   * Verifica se a peça tem algum movimento disponivel
   * @param posicoesTabuleiro Matriz de posicoes do tabuleiro.
   * @return TRUE quando há jogada disponivel
   */
  bool verificaDisponibilidadeMovimentar(vector<vector<Posicao *>> *posicoesTabuleiro);
};

#endif //_PECA_H
