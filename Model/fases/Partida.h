/**
 * Project Untitled
 */


#ifndef _PARTIDA_H
#define _PARTIDA_H

#include "../jogador/Jogador.h"


class Partida {
public: 
    vector<*Jogador> jogadores;
    *Tabuleiro tabuleiro;
    Jogador 2;
    
void iniciarPartida();
    
void salvarPartida();
    
void encerrarPartida();
private: 
    int jogador_atual;
};

#endif //_PARTIDA_H