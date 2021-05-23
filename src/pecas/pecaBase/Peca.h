#pragma once

#include <string>
#include <vector>
#include "../pecaDAO/PecaDAO.h"
#include "../../posicao/Posicao.h"

using namespace std;

class Posicao;
class PecaDAO;

class Peca
{
protected:
  bool sentidoPraFrente;
  bool primeiraJogada;
  string estilo;
  string simbolo;
  bool emXeque;
  int codigo;
  PecaDAO *pecaDAO;
  int sql_idPeca;

public:
  Posicao *posicao;

  Peca(string estilo, bool sentidoPraFrente);
  Peca(int idPeca);
  ~Peca();

  /**
     * @return retorna TRUE caso a peca esteja em Xeque.
     */
  bool getXeque();

  /**
     * @return Booleano com estado atual.
     */
  bool getPrimeiraJogada();

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

  /**
   * Salva uma peca e seus estados se
   * @param idPacotePeca id do pacote de pecas associado
   * @return 0 quando ocorrer um erro OU o id da peca
  */
  int salvar(int idPacotePeca);

  /**
   * @return Retorna sql_ID da peca
  */
  int getSqlIdPeca();
};
