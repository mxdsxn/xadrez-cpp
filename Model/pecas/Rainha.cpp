#include "Rainha.h"

Rainha::Rainha(string estilo, Posicao *posicao = nullptr, Tabuleiro *tabuleiro) : Peca(estilo)
{
    this->simbolo = this->estilo == "black" ? "♛" : "♕";
    this->posicao = posicao;
    this->tabuleiro = tabuleiro;
}
Rainha::~Rainha() {}

vector<Posicao *> Rainha::getPosicoesValidas()
{
    vector<Posicao *> posicoesValidas;

    return posicoesValidas;
}