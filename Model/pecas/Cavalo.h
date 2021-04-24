#pragma once

#include "Peca.h"

class Cavalo : virtual public Peca
{
public:
 Cavalo(string estilo, Posicao *posicao, Tabuleiro *tabuleiro);
 ~Cavalo();

 /**
 * @return Retorna lista de posições validas para o Cavalo, de acordo com sua regra de movimentação.
 */
 vector<Posicao *> getPosicoesValidas();

 /**
 * @param novaPosicao Nova posição para o Cavalo
 * @return Retorna 'true' quando o Cavalo foi movimentado com sucesso
 */
 bool movimentar(Posicao *novaPosicao);

 /**
 * @param posicaoReiAdversario Posição do Rei adversario
 * @return Retorna 'true' quando o Cavalo coloca o Rei adversario em xeque
 */
 bool verificaXequeAdversario(Posicao *posicaoReiAdversario);
};
