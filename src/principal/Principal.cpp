#include "../principal/Principal.h"
#include "../utils/utils.h"
#include <iostream>

Principal::Principal()
{
  this->tabuleiroExibicao = new Tabuleiro();
  this->controleJogo = new Controle();
}

void Principal::iniciar()
{
  int menuOption = 0;

  cout << "  >>> M-Xadrez <<<"
       << endl
       << endl;

  this->tabuleiroExibicao->show(true, false);
  cout << endl
       << endl;

  do
  {
    menuOption = this->mostrarMenu();

    switch (menuOption)
    {
    case 1:
      this->controleJogo->novoJogo();
      break;

    case 2:
      this->controleJogo->recuperaJogo();
      break;

    case 0:
      cout << "  Até a proxima!" << endl;
      break;

    default:
      break;
    }

  } while (menuOption != 0);
}

int Principal::mostrarMenu()
{
  int menuOption = 0;
  cout << "1 - Novo Jogo" << endl
       << "2 - Carregar Jogo" << endl
       << "0 - Sair" << endl
       << endl;
  cin >> menuOption;
  cleanBuffer();

  return menuOption;
}
