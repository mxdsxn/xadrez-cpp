#pragma once

#include "./Peca.h"
using namespace std;

class Peca;

class Peao : public Peca
{
public:
 Peao(string estilo);
 ~Peao();

 /**
 * @return Retorna lista de posições validas para o Peão, de acordo com sua regra de movimentação.
 */
 //vector<Posicao *> getPosicoesValidas();

 /**
 * @param novaPosicao Nova posição para o Peão
 * @return Retorna 'true' quando o Peão foi movimentado com sucesso
 */
 bool movimentar(int xPosNova, int yPosNova);

 /**
 * @param posicaoReiAdversario Posição do Rei adversario
 * @return Retorna 'true' quando o Peão coloca o Rei adversario em xeque
 */
 bool verificaXequeAdversario(int xPosReiAdversario, int yPosReiAdversario);
};