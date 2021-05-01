#ifndef _TABULEIRO_H
#define _TABULEIRO_H

#include <vector>
#include "./Posicao.h"
#include "../pecas/PecasPack.h"

using namespace std;

class Tabuleiro
{
public:
    PecasPack *pecasJogador1 = nullptr;
    PecasPack *pecasJogador2 = nullptr;

    Tabuleiro();
    ~Tabuleiro();

    /**
     * @return Lista de Posições disponíveis.
     */
    vector<Posicao *> getPosicoes();

    /**
     * @return [VOID] Exibe o tabuleiro de xadrez e a disposição de peças.
     */
    void show();

private:
    vector<Posicao *> posicoes;
};

#endif //_TABULEIRO_H