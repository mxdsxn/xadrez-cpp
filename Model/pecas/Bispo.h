#pragma once

#include "Peca.h"

class Bispo : virtual public Peca
{
public:
 Bispo(string estilo, Posicao *posicao, Tabuleiro *tabuleiro);
 ~Bispo();

 /**
 * @return Retorna lista de posições validas para o Bispo, de acordo com sua regra de movimentação.
 */
 vector<Posicao *> getPosicoesValidas();

 /**
 * @param novaPosicao Nova posição para o Bispo
 * @return Retorna 'true' quando o Bispo foi movimentado com sucesso
 */
 bool movimentar(Posicao *novaPosicao);

 /**
 * @param posicaoReiAdversario Posição do Rei adversario
 * @return Retorna 'true' quando o Bispo coloca o Rei adversario em xeque
 */
 bool verificaXequeAdversario(Posicao *posicaoReiAdversario);
};
