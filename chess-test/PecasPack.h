#pragma once

#include "./Peca.h"
#include "./Posicao.h"

class Peca;

class PecasPack
{
private:
  string estilo;
  vector<Peca *> peoes;
  Peca *rei;

public:
  PecasPack(string estilo, bool sentidoPraFrente);
  ~PecasPack();

  /**
   * @return Lista de posicoes com as peças pecasDisponiveis
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
};
