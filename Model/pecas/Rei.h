/**
 * Project Untitled
 */


#ifndef _REI_H
#define _REI_H

#include "../PecaRealeza.h"
#include "../PecaRealeza.h"


class Rei: public PecaRealeza, public PecaRealeza {
public: 
    
vector<*Posicao> getPosicoesValidas();
    
/**
 * @param posicao_origem
 * @param posicao_destino
 */
boolean getXeque(*Posicao posicao_origem, *Posicao posicao_destino);
};

#endif //_REI_H