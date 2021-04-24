#pragma once

#include "Peca.h"

class Peao : virtual public Peca
{
public:
 Peao(string estilo, Posicao *posicao, Tabuleiro *tabuleiro);
 ~Peao();

 /**
 * @return Retorna lista de posições validas para o Peão, de acordo com sua regra de movimentação.
 */
 vector<Posicao *> getPosicoesValidas();

 /**
 * @param novaPosicao Nova posição para o Peão
 * @return Retorna 'true' quando o Peão foi movimentado com sucesso
 */
 bool movimentar(Posicao *novaPosicao);

 /**
 * @param posicaoReiAdversario Posição do Rei adversario
 * @return Retorna 'true' quando o Peão coloca o Rei adversario em xeque
 */
 bool verificaXequeAdversario(Posicao *posicaoReiAdversario);
};