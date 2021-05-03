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
void legendaNumerica(int jogador)
{
  cout << " ";
  for (int i = jogador == 1 ? 1 : 8;
       jogador == 1 ? i <= 8 : i >= 1;
       jogador == 1 ? i++ : i--)
  {
    cout << "  " << i << " ";
  }
  cout << endl;
}

Tabuleiro::Tabuleiro()
{
  // instancia pacote de peças para 2 jogadores
  this->pecasBrancas = new PecasPack("branco", true);
  this->pecasPretas = new PecasPack("preto", false);

  // instancia os posicoes do tabuleiro numa matriz
  for (int y = 0; y < 8; y++)
  {
    vector<Posicao *> novaLinha;

    for (int x = 0; x < 8; x++)
    {
      Posicao *novoPosicao = new Posicao(x, y);
      novaLinha.push_back(novoPosicao);
    }

    this->matrizPosicoes.push_back(novaLinha);
  }

  // coloca as peoes do Jogador1 nas posicoes iniciais
  vector<Posicao *> *linhaPeoesJogador1 = &(this->matrizPosicoes[1]);
  this->pecasBrancas->setPosicaoIncialPeoes(linhaPeoesJogador1);
  //this->pecasBrancas->setPosicaoIncialRealeza(linhaRealezaJogador1);

  // coloca as peoes do Jogador2 nas posicoes iniciais
  vector<Posicao *> *linhaPeoesJogador2 = &(this->matrizPosicoes[6]);
  this->pecasPretas->setPosicaoIncialPeoes(linhaPeoesJogador2);
  //this->pecasPretas->setPosicaoIncialRealeza(linhaRealezaJogador2);
}

Tabuleiro ::~Tabuleiro() {}

void Tabuleiro::show(int jogador)
{
  if (jogador != 1 && jogador != 2)
    return;

  clear();

  legendaNumerica(jogador);

  // Letra da legenda - ASCII
  int legendaLinhaInt = jogador == 1 ? 72 : 65;

  int linhaInicial = jogador == 1 ? this->matrizPosicoes.size() - 1 : 0;
  int linhaFinal = jogador == 1 ? 0 : this->matrizPosicoes.size() - 1;

  // esse logica usando o paramentro 'jogador' define qual o lado do tabuleiro sera apresentado
  for (int y = linhaInicial;
       jogador == 1 ? y >= linhaFinal : y <= linhaFinal;
       jogador == 1 ? y-- : y++)
  {
    vector<Posicao *> linhaAtual = this->matrizPosicoes[y];

    cout << (char)legendaLinhaInt;

    int inicioLinha = jogador == 1 ? 0 : linhaAtual.size() - 1;
    int finalLinha = jogador == 1 ? linhaAtual.size() - 1 : 0;

    for (int x = inicioLinha;
         jogador == 1 ? x <= finalLinha : x >= finalLinha;
         jogador == 1 ? x++ : x--)
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

  legendaNumerica(jogador);
}

vector<Posicao *> Tabuleiro::getPosicaoPecasDisponiveis(int jogador)
{
  vector<Posicao *> pecasDisponiveis;

  if (jogador == 1 || jogador == 2)
  {
    string estiloJogadorSelecionado = (jogador == 1
                                           ? this->pecasBrancas
                                           : this->pecasPretas)
                                          ->estilo;

    for (int x = 0; x < 8; x++)
      for (int y = 0; y < 8; y++)
      {
        Posicao *posicaoAtual = this->matrizPosicoes[x][y];
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

vector<vector<Posicao *>> *Tabuleiro::getTodasPosicoes()
{
  vector<vector<Posicao *>> *matrizPosicoes;
  if (this)
  {
    matrizPosicoes = &this->matrizPosicoes;
  }

  return matrizPosicoes;
}

PecasPack *Tabuleiro::getPecasBrancas()
{
  PecasPack *pecasBrancas;
  if (this)
  {
    pecasBrancas = this->pecasBrancas;
  }
  return pecasBrancas;
}

PecasPack *Tabuleiro::getPecasPretas()
{
  PecasPack *pecasPretas;
  if (this)
  {
    pecasPretas = this->pecasPretas;
  }
  return pecasPretas;
}
