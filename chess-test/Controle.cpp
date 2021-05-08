#include "./Controle.h"
#include "./clear.h"
#include <iostream>

Controle::Controle()
{
  this->partidaAtual = nullptr;
  this->fabricaPartida = new FabricaPartida();
}

void Controle::novoJogo()
{
  int opcaoJogo = 0;

  opcaoJogo = this->mostrarMenuNovoJogo();

  this->partidaAtual = this->fabricaPartida->novaPartida(opcaoJogo);

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
         << "1 - Partida Tradicional" << endl
         << "1 - Partida Tradicional" << endl
         << endl;
    cin >> opcaoPartida;

    clear();
  } while (opcaoPartida != 1 && opcaoPartida != 2 && opcaoPartida != 3);

  return opcaoPartida;
}
