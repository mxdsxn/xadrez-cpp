/**
 * Project Untitled
 */


#ifndef _PECA_H
#define _PECA_H

class Peca {
public: 
    string tipo;
    *Posicao posicao;
    string estilo;
    *Tabuleiro tabuleiro;
    
/**
 * @param nova_posicao
 */
boolean movimentar(*Posicao nova_posicao);
    
vector<*Posicao> getPosicoesValidas();
    
/**
 * @param posicao_rei
 */
boolean verificaXeque(*Posicao posicao_rei);
private: 
    int codigo;
    string simbolo;
};

#endif //_PECA_H