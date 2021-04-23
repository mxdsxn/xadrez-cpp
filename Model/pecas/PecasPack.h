/**
 * Project Untitled
 */


#ifndef _PECASPACK_H
#define _PECASPACK_H

#include "Peca.h"
#include "Peao.h"
#include "Torre.h"
#include "Bispo.h"
#include "Cavalo.h"
#include "Rei.h"
#include "Rainha.h"


class PecasPack {
public: 
    Rei rei;
    Rainha rainha;
    vector<Torre> torres;
    vector<Cavalo> cavalos;
    vector<Bispo> bispos;
    vector<Peao> peoes;
    string estilo;
    Peca 8;
    Peao 8;
    Torre 2;
    Bispo 2;
    Cavalo 2;
    Rei 1;
    Rainha 1;
    
vector<Pecas> getPecasDisponiveis();
    
/**
 * @param peca_removida
 */
boolean deletaPeca(*Peca peca_removida);
};

#endif //_PECASPACK_H