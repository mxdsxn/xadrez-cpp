#include <iostream>
#include <string>
#include "Tabuleiro.h"

using namespace std;

Tabuleiro::Tabuleiro()
{
    this->pecasJogador1 = new PecasPack("white", this);
    this->pecasJogador1 = new PecasPack("black", this);
}

Tabuleiro ::~Tabuleiro() {}

void Tabuleiro::show()
{
    cout << " "
         << "  1 "
         << "  2 "
         << "  3 "
         << "  4 "
         << "  5 "
         << "  6 "
         << "  7 "
         << "  8 "
         << endl;
    for (int i = 65; i <= 72; i++)
    {
        char key = (char)i;
        cout << key
             << " [ ]"
             << " [ ]"
             << " [ ]"
             << " [ ]"
             << " [ ]"
             << " [ ]"
             << " [ ]"
             << " [ ]"
             << " " << key
             << endl;
    }
    cout << " "
         << "  1 "
         << "  2 "
         << "  3 "
         << "  4 "
         << "  5 "
         << "  6 "
         << "  7 "
         << "  8 "
         << endl;
}

vector<Posicao *> Tabuleiro::getPosicoes()
{
    vector<Posicao *> posicoes;

    return posicoes;
}