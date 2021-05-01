#ifndef _REI_H
#define _REI_H

#include "./Peca.h"

class Posicao;
class Tabuleiro;

class Rei : public Peca
{
public:
 Rei(string estilo, Tabuleiro *tabuleiro, Posicao *posicao);
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

#endif //_REI_H
