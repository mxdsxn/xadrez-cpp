#include "./Controle.h"
#include "../utils/utils.h"
#include "../partidas/partidaDAO/PartidaDAO.h"
#include <iostream>
#include <vector>

using namespace std;

Controle::Controle()
{
  this->partidaAtual = nullptr;
  this->fabricaPartida = new FabricaPartida();
}

void Controle::novoJogo()
{
  clear();

  int opcaoJogo = 0;
  string nomePrimeiroJogador, nomeSegundoJogador;

  opcaoJogo = this->mostrarMenuNovoJogo();

  cout << "Nome do primeiro jogador: ";
  getline(cin, nomePrimeiroJogador);

  cout << endl;

  cout << "Nome do segundo jogador: ";
  getline(cin, nomeSegundoJogador);

  this->partidaAtual = this->fabricaPartida->novaPartida(opcaoJogo, nomePrimeiroJogador, nomeSegundoJogador);
  this->partidaAtual->iniciarPartida();
}

void Controle::recuperaJogo()
{
  clear();

  PartidaDAO *partidaDAO = new PartidaDAO();
  vector<Partida *> listaPartidas = partidaDAO->recuperar();

  int indiceSelecionado = this->monstraMenuRecuperaJogo(listaPartidas);

  this->partidaAtual = listaPartidas[indiceSelecionado];
  this->partidaAtual->iniciarPartida();
}

int Controle::monstraMenuRecuperaJogo(vector<Partida *> listaPartidas)
{
  int menuOption;

  do
  {
    cout << "Selecione a partida desejada: " << endl
         << endl;

    for (int indice = 0; indice < listaPartidas.size(); indice++)
    {
      Partida *partidaAtual = listaPartidas[indice];
      cout << indice << " - partidaID: " << partidaAtual->getSqlIdPartida() << endl;
    }

    cin >> menuOption;
    cleanBuffer();
    clear();

  } while (!(menuOption >= 0 && menuOption < listaPartidas.size()));

  return menuOption;
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
