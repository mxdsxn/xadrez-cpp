#include "Bispo.h"

Bispo::Bispo(string estilo, Posicao *posicao = nullptr, Tabuleiro *tabuleiro) : Peca(estilo)
{
    this->simbolo = this->estilo == "black" ? "♝" : "♗";
    this->posicao = posicao;
    this->tabuleiro = tabuleiro;
}
Bispo::~Bispo() {}

vector<Posicao *> Bispo::getPosicoesValidas()
{
    vector<Posicao *> posicoesValidas;

    return posicoesValidas;
}