#ifndef _CAVALO_H
#define _CAVALO_H

#include "./Peca.h"

class Posicao;
class Tabuleiro;

class Cavalo : public Peca
{
public:
 Cavalo(string estilo, Tabuleiro *tabuleiro, Posicao *posicao);
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

#endif //_CAVALO_H