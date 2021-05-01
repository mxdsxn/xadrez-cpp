#include "Peao.h"

Peao::Peao(string estilo, Tabuleiro *tabuleiro, Posicao *posicao = nullptr) : Peca(estilo)
{
    this->simbolo = this->estilo == "black" ? "♟" : "♙";
    this->posicao = posicao;
    this->tabuleiro = tabuleiro;
}
Peao::~Peao() {}

vector<Posicao *> Peao::getPosicoesValidas()
{
    vector<Posicao *> posicoesValidas;

    return posicoesValidas;
}