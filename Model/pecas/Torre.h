#ifndef _TORRE_H
#define _TORRE_H

#include "./Peca.h"

class Posicao;
class Tabuleiro;

class Torre : public Peca
{
public:
 Torre(string estilo, Tabuleiro *tabuleiro, Posicao *posicao);
 ~Torre();

 /**
 * @return Retorna lista de posições validas para a Torre, de acordo com sua regra de movimentação.
 */
 vector<Posicao *> getPosicoesValidas();

 /**
 * @param novaPosicao Nova posição para a Torre
 * @return Retorna 'true' quando a Torre foi movimentada com sucesso
 */
 bool movimentar(Posicao *novaPosicao);

 /**
 * @param posicaoReiAdversario Posição do Rei adversario
 * @return Retorna 'true' quando a Torre coloca o Rei adversario em xeque
 */
 bool verificaXequeAdversario(Posicao *posicaoReiAdversario);
};

#endif //_TORRE_H
