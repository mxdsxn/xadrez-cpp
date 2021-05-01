/**
 * Project Untitled
 */

#ifndef _PRINCIPAL_H
#define _PRINCIPAL_H

#include <vector>

#include "jogador/Jogador.h"
#include "fases/Partida.h"
#include "controleDados/ControleDados.h"

using namespace std;

class Principal
{
public:
    vector<Partida *> fases;
    //Jogador 2;
    //Partida 1;
    //ControleDados 1;
private:
    vector<Jogador *> jogadores;
};

#endif //_PRINCIPAL_H