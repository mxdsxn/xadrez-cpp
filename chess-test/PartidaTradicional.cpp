#include "./PartidaTradicional.h"
#include "./utils.h"
#include <iostream>

struct CoordenadasStr
{
  string x, y;
};

/**
 * Coverte coordenadas de uma posição para ser mostrada no console
 * @param posicao Posição que precisa ser formatada as coordenadas
 * @return Retorna uma lista de tamanho 2. Primeiro item X, segundo item, Y.
 * | Lista vazia caso as coordenadas não atendam a regra.
 */
CoordenadasStr posicaoToCoordStr(Posicao *posicao)
{
  CoordenadasStr coordenadasFormatadas;

  int x = posicao->getX();
  int y = posicao->getY();

  if ((x >= 0 && x < 8) && (y >= 0 && y < 8))
  {
    coordenadasFormatadas.y = to_string(y + 1);
    coordenadasFormatadas.x = (char)(x + 65);
  }

  return coordenadasFormatadas;
}

/**
 * Formata coordenadas para o formato [A, 1]
 * @param coordenadas Coordenadas para serem formatadas.
 * @return Retorna uma string no formato [A, 1].
 */
string formataCoordenadas(CoordenadasStr coordenadas)
{
  return "[" + coordenadas.x + ", " + coordenadas.y + "]";
}

PartidaTradicional::PartidaTradicional(string nomePrimeiroJogador, string nomeSegundoJogador) : Partida()
{
  PecasPack *pecasBrancas = this->tabuleiro->getPecasBrancas();
  PecasPack *pecasPretas = this->tabuleiro->getPecasPretas();

  this->primeiroJogador = new Jogador(nomePrimeiroJogador, pecasBrancas);
  this->segundoJogador = new Jogador(nomeSegundoJogador, pecasPretas);
  this->turnoPrimeiroJogador = true;
}

void PartidaTradicional::mostrarTabuleiro(bool turnoPrimeiroJogador)
{
  if (this)
  {
    this->tabuleiro->show(turnoPrimeiroJogador);
  }
}

Peca *PartidaTradicional::selecionarPecaDisponivel(bool primeiroJogador)
{
  int indicePecaSelecionada = 0;

  Jogador *jogadorAtual = primeiroJogador ? this->primeiroJogador : this->segundoJogador;
  PecasPack *pecasJogadorAtual = jogadorAtual->getPecas();
  vector<Peca *> pecasDisponiveis = pecasJogadorAtual->getPecasDisponiveis();
  Peca *pecaSelecionada = nullptr;

  do
  {
    std::cout << "Selecione um das suas peças disponiveis: "
              << endl
              << endl;

    for (int indice = 0; indice < pecasDisponiveis.size(); indice++)
    {
      Peca *pecaAtual = pecasDisponiveis[indice];
      Posicao *posicaoAtual = pecaAtual->getPosicaoAtual();

      std::cout << (indice + 1)
                << " - "
                << posicaoAtual->showSimbolo()
                << " | "
                << formataCoordenadas(posicaoToCoordStr(posicaoAtual))
                << endl;
    }
    std::cout << endl;
    cin >> indicePecaSelecionada;
    cleanBuffer();

  } while (indicePecaSelecionada <= 0 || indicePecaSelecionada > pecasDisponiveis.size());

  pecaSelecionada = pecasDisponiveis[indicePecaSelecionada - 1];

  return pecaSelecionada;
}

void PartidaTradicional::iniciarPartida()
{
  if (this)
  {
    bool jogoEncerrado = false;
    bool turnoPrimeiroJogador = this->turnoPrimeiroJogador;
    Jogador *jogadorAtual = nullptr;
    Peca *pecaSelecionada = nullptr;

    do
    {
      jogadorAtual = turnoPrimeiroJogador ? this->primeiroJogador : this->segundoJogador;
      turnoPrimeiroJogador = this->turnoPrimeiroJogador;

      this->mostrarTabuleiro(turnoPrimeiroJogador);
      pecaSelecionada = this->selecionarPecaDisponivel(turnoPrimeiroJogador);

      this->turnoPrimeiroJogador = !turnoPrimeiroJogador;

    } while (!jogoEncerrado);
  }
}

void PartidaTradicional::salvarPartida() {}
void PartidaTradicional::encerrarPartida() {}
