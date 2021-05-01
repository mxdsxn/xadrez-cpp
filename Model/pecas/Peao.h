#ifndef _PEAO_H
#define _PEAO_H

#include "./Peca.h"
using namespace std;

class Posicao;
class Tabuleiro;

class Peao : public Peca
{
public:
 Peao(string estilo, Tabuleiro *tabuleiro, Posicao *posicao);
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

#endif //_PEAO_H