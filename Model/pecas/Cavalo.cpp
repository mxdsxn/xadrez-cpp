#include "Cavalo.h"

Cavalo::Cavalo(string estilo, Posicao *posicao = nullptr, Tabuleiro *tabuleiro) : Peca(estilo)
{
    this->simbolo = this->estilo == "black" ? "♞" : "♘";
    this->posicao = posicao;
    this->tabuleiro = tabuleiro;
}
Cavalo::~Cavalo() {}

vector<Posicao *> Cavalo::getPosicoesValidas()
{
    vector<Posicao *> posicoesValidas;

    return posicoesValidas;
}
