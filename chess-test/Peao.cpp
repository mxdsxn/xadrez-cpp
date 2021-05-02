#include "./Peao.h"
#include <iostream>

using namespace std;

Peao::Peao(string estilo) : Peca(estilo)
{
    this->simbolo = this->estilo == "preto" ? "♙" : "♟";
}
Peao::~Peao() {}

/*
vector<Posicao *> Peao::getPosicoesValidas()
{
    vector<Posicao *> posicoesValidas;
    cout << "[PEAO] - Metodo `getPosicoesValidas()" << endl;

    return posicoesValidas;
}*/

bool Peao::movimentar(int xPosNova, int yPosNova)
{
    cout << "[PEAO] - Metodo `movimentar()" << endl;
    return false;
}

bool Peao::verificaXequeAdversario(int xPosReiAdversario, int yPosReiAdversario)
{
    cout << "[PEAO] - Metodo `verificaXequeAdversario()" << endl;
    return false;
}
