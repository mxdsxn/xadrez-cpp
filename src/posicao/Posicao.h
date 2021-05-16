#pragma once
#include <string>
#include "../pecas/pecaBase/Peca.h"

using namespace std;

class Peca;

class Posicao
{
private:
  int x;
  int y;
  Peca *pecaAtual;
  bool posicaoPreta;
  string simbolo;

public:
  Posicao(int x, int y, bool posicaoPreta);
  ~Posicao();

  /**
     * @return Retorna posição formatada para o formato do tabuleiro.
     */
  string showPosicao();

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
     * @return Ponteiro da peça atual na peça.
     */
  Peca *getPecaAtual();

  /**
     * Setta como `nullptr` a peça da posição
     * @return Retorna 'true' quando a peça foi removida com sucesso
     */
  bool removePeca();

  /**
     * @return Retorna coordenada X.
     */
  int getX();

  /**
     * @return Retorna coordenada Y.
     */
  int getY();
};
