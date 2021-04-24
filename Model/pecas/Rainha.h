#pragma once

#include "Peca.h"

class Rainha : virtual public Peca
{
public:
 Rainha(string estilo, Posicao *posicao, Tabuleiro *tabuleiro);
 ~Rainha();

 /**
 * @return Retorna lista de posições validas para a Rainha, de acordo com sua regra de movimentação.
 */
 vector<Posicao *> getPosicoesValidas();

 /**
 * @param novaPosicao Nova posição para a Rainha
 * @return Retorna 'true' quando a Rainha foi movimentada com sucesso
 */
 bool movimentar(Posicao *novaPosicao);

 /**
 * @param posicaoReiAdversario Posição do Rei adversario
 * @return Retorna 'true' quando a Rainha coloca o Rei adversario em xeque
 */
 bool verificaXequeAdversario(Posicao *posicaoReiAdversario);
};