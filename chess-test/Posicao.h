#pragma once
#include <string>
#include "./Peca.h"

using namespace std;

class Peca;

class Posicao
{
public:
  int x;
  int y;
  Peca *pecaAtual;

  Posicao(int x, int y);
  ~Posicao();

  /**
     * @return Retorna posição formatada para o formato do tabuleiro.
     */
  string show();

  /**
     * @return Retorna valor do simbolo da peça que está na posição, ou vazio caso não haja peça.
     */
  string showSimbolo();

  /**
     * @param novaPeca Nova peça naquela posição.
     * @return Retorna 'true' quando a peça foi inserida corretamente.
     */
  bool setPeca(Peca *novaPeca);

  /**
     * Setta como `nullptr` a peça da posição
     * @return Retorna 'true' quando a peça foi removida com sucesso
     */
  bool removePeca();
};
