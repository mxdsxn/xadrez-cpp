#include "Peao.h"

Peao::Peao(string estilo, Posicao *posicao = nullptr, Tabuleiro *tabuleiro) : Peca(estilo)
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