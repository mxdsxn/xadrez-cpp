#include "./Controle.h"
#include "../utils/utils.h"
#include <iostream>

Controle::Controle()
{
  this->partidaAtual = nullptr;
  this->fabricaPartida = new FabricaPartida();
}

void Controle::novoJogo()
{
  int opcaoJogo = 0;
  string nomePrimeiroJogador, nomeSegundoJogador;

  clear();
  opcaoJogo = this->mostrarMenuNovoJogo();

  cout << "Nome do primeiro jogador: ";
  getline(cin, nomePrimeiroJogador);

  cout << endl;

  cout << "Nome do segundo jogador: ";
  getline(cin, nomeSegundoJogador);

  this->partidaAtual = this->fabricaPartida->novaPartida(opcaoJogo, nomePrimeiroJogador, nomeSegundoJogador);
  this->partidaAtual->iniciarPartida();
}

int Controle::mostrarMenuNovoJogo()
{
  int opcaoPartida = 0;

  do
  {
    cout << "Escolha a modalidade de jogo desejada:"
         << endl
         << endl;

    cout << "1 - Partida Tradicional" << endl
         << "2 - Partida Turno temporizado" << endl
         << "3 - Partida Por Pontos" << endl
         << endl;

    cin >> opcaoPartida;
    cleanBuffer();

    clear();
  } while (opcaoPartida != 1 && opcaoPartida != 2 && opcaoPartida != 3);

  return opcaoPartida;
}
