/**
 * Project Untitled
 */


#ifndef _TABULEIRO_H
#define _TABULEIRO_H

#include "../pecas/PecasPack.h"
#include "Posicao.h"


class Tabuleiro {
public: 
    vector<*PecasPack> pacote_pecas;
    PecasPack 2;
    Posicao 64;
    
vector<*Posicao> getPosicoes();
private: 
    vector<*Posicao> posicoes;
};

#endif //_TABULEIRO_H