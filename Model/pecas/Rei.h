#pragma once

#include "Peca.h"

class Rei : virtual public Peca
{
public:
 Rei(string estilo, Posicao *posicao, Tabuleiro *tabuleiro);
 ~Rei();

 /**
 * @return Retorna lista de posições validas para o Rei, de acordo com sua regra de movimentação.
 */
 vector<Posicao *> getPosicoesValidas();

 /**
 * @param novaPosicao Nova posição para o Rei
 * @return Retorna 'true' quando o Rei foi movimentada com sucesso
 */
 bool movimentar(Posicao *novaPosicao);

 /**
 * @param posicaoReiAdversario Posição do Rei adversario
 * @return Retorna 'true' quando o Rei coloca o Rei adversario em xeque
 */
 bool verificaXequeAdversario(Posicao *posicaoReiAdversario);

 /**
 * @param posicao_destino Posição futura do Rei
 * @return Retorna 'true' quando aquela posição de destino for por o Rei em xeque ou 'false' quando o Rei pode mudar de posição
 */
 bool verificaXeque(Posicao *posicao_destino);
};