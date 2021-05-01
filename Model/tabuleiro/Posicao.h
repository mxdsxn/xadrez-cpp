#ifndef _POSICAO_H
#define _POSICAO_H

#include <string>
#include "../pecas/Peca.h"

using namespace std;

class Peca;

class Posicao
{
public:
    int x;
    int y;
    Peca *pecaAtual;

    Posicao(int x, int y);
    ~Posicao();

    /**
     * @return Retorna valor do simbolo da peça que está na posição, ou vazio caso não haja peça.
     */
    string showSimbolo();

    /**
     * @param novaPeca Nova peça naquela posição.
     * @return Retorna 'true' quando a peça foi inserida corretamente.
     */
    bool setPeca(Peca *novaPeca);

    /**
     * @return Retorna 'true' quando a peça foi removida com sucesso
     */
    bool removePeca();
};

#endif //_POSICAO_H