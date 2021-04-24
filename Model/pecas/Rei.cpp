#include "Rei.h"

Rei::Rei(string estilo, Posicao *posicao = nullptr, Tabuleiro *tabuleiro) : Peca(estilo)
{
    this->simbolo = this->estilo == "black" ? "♚" : "♔";
    this->posicao = posicao;
    this->tabuleiro = tabuleiro;
}
Rei::~Rei() {}

vector<Posicao *> Rei::getPosicoesValidas()
{
    vector<Posicao *> posicoesValidas;

    return posicoesValidas;
}

bool Rei::verificaXeque(Posicao *posicao_destino)
{
    return false;
}