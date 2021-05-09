#pragma once

#include "./Peca.h"
#include "./Posicao.h"
#include "./Tabuleiro.h"

class Peca;
class Tabuleiro;

class PecasPack
{
private:
  string estilo;
  vector<Peca *> peoes;
  Peca *rei;
  Tabuleiro *tabuleiro;
  bool emXeque;

public:
  PecasPack(string estilo, bool sentidoPraFrente, Tabuleiro *tabuleiro);
  ~PecasPack();

  /**
   * @return Lista de pecas disponiveis para executar jogada
   */
  vector<Peca *> getPecasDisponiveis();

  /**
     * @return Retorna `branco` ou `preto`.
     */
  string getEstilo();

  /**
     * @return Retorna posição atual do rei.
     */
  Posicao *getPosicaoRei();

  /**
     * @return Retorna TRUE quando alguma das peças do pacote coloca o Rei adversario em Xeque.
     */
  bool verificaXequeAdversario(Posicao *posicaoReiAdversario);

  /**
     * Setta posicoes inciais para os peoes.
     * @param linhaInicialPeoes Linha inicial dos Peoes no tabuleiro .
     */
  void setPosicaoInicialPeoes(vector<Posicao *> *linhaInicialPeoes);

  /**
     * Setta posicoes inciais para as peças da realeza.
     * @param linhaInicialRealeza Linha inicial dos Peoes no tabuleiro .
     */
  void setPosicaoInicialRealeza(vector<Posicao *> *linhaInicialRealeza);

  /**
     * @param emXeque TRUE quando o rei estiver em xeque.
     */
  void setXeque(bool emXeque);

  /**
     * Faz uma analise em uma lista de possiveis jogadas, filtrando por jogadas que não deixem o Rei em xeque.
     */
  vector<Posicao *> validaRiscoXeque(Peca *pecaMovimentar);

  /**
     * @return Lista com todas as peças do pacote
     */
  vector<Peca *> todasPecas();
};
