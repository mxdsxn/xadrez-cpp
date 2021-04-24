#pragma once

//#include "../pecas/PecasPack.h"
#include "Posicao.h"
#include <vector>

using namespace std;

class Tabuleiro
{
public:
    //PecasPack *pecasJogador1 = nullptr;
    //PecasPack *pecasJogador2 = nullptr;

    Tabuleiro();
    ~Tabuleiro();

    vector<Posicao *> getPosicoes();
    void show();

private:
    vector<Posicao *> posicoes;
};
