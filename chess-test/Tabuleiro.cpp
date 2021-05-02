#include <iostream>
#include <string>
#include "./Tabuleiro.h"

using namespace std;

/**
 * Limpa o console
 */
void clear()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

/**
 * Mostra no console a regua numerica que legenda o tabuleiro
 */
void legendaNumerica()
{
    cout << " ";
    for (int i = 1; i <= 8; i++)
    {
        cout << "  " << i << " ";
    }
    cout << endl;
}

Tabuleiro::Tabuleiro()
{
    // instancia pacote de peças para 2 jogadores
    this->pecasJogador1 = new PecasPack("preto");
    this->pecasJogador2 = new PecasPack("branco");

    // instancia os posicoes do tabuleiro numa matriz
    for (int y = 0; y < 8; y++)
    {
        vector<Posicao *> novaLinha;

        for (int x = 0; x < 8; x++)
        {
            Posicao *novoPosicao = new Posicao(x, y);
            novaLinha.push_back(novoPosicao);
        }

        this->posicoes.push_back(novaLinha);
    }

    // coloca as peoes do Jogador1 nas posicoes iniciais
    vector<Posicao *> *linhaPeoesJogador1 = &(this->posicoes[1]);
    this->pecasJogador1->setPosicaoIncialPeoes(linhaPeoesJogador1);
    //this->pecasJogador1->setPosicaoIncialRealeza(linhaRealezaJogador1);

    // coloca as peoes do Jogador2 nas posicoes iniciais
    vector<Posicao *> *linhaPeoesJogador2 = &(this->posicoes[6]);
    this->pecasJogador2->setPosicaoIncialPeoes(linhaPeoesJogador2);
    //this->pecasJogador2->setPosicaoIncialRealeza(linhaRealezaJogador2);
}

Tabuleiro ::~Tabuleiro() {}

void Tabuleiro::show(int jogador)
{
    if (jogador != 1 && jogador != 2)
        return;

    clear();

    legendaNumerica();

    // Letra da legenda - ASCII
    int legendaLinhaInt = jogador == 1 ? 72 : 65;

    int linhaInicial = jogador == 1 ? this->posicoes.size() - 1 : 0;
    int linhaFinal = jogador == 1 ? 0 : this->posicoes.size() - 1;

    // esse logica usando o paramentro 'jogador' define qual o lado do tabuleiro sera apresentado
    for (int y = linhaInicial;
         jogador == 1 ? y >= linhaFinal : y <= linhaFinal;
         jogador == 1 ? y-- : y++)
    {
        vector<Posicao *> linhaAtual = this->posicoes[y];

        cout << (char)legendaLinhaInt;

        for (int x = 0; x < linhaAtual.size(); x++)
        {
            Posicao *posicaoAtual = linhaAtual[x];
            cout << " " << posicaoAtual->show();
        }

        cout << " "
             << (char)legendaLinhaInt
             << endl;

        jogador == 1
            ? legendaLinhaInt--
            : legendaLinhaInt++;
    }

    legendaNumerica();
}

vector<Posicao *> Tabuleiro::getPosicaoPecasDisponiveis(int jogador)
{
    vector<Posicao *> pecasDisponiveis;

    if (jogador == 1 || jogador == 2)
    {
        string estiloJogadorSelecionado = (jogador == 1
                                               ? this->pecasJogador1
                                               : this->pecasJogador2)
                                              ->estilo;

        for (int x = 0; x < 8; x++)
            for (int y = 0; y < 8; y++)
            {
                Posicao *posicaoAtual = this->posicoes[x][y];
                if (posicaoAtual->pecaAtual != nullptr)
                {
                    if (posicaoAtual->pecaAtual->estilo == estiloJogadorSelecionado)
                    {
                        pecasDisponiveis.push_back(posicaoAtual);
                    }
                }
            }
    }
    return pecasDisponiveis;
}