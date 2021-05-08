#include "./PartidaTradicional.h"

PartidaTradicional::PartidaTradicional(string nomePrimeiroJogador, string nomeSegundoJogador) : Partida()
{
  PecasPack *pecasBrancas = this->tabuleiro->getPecasBrancas();
  PecasPack *pecasPretas = this->tabuleiro->getPecasPretas();

  this->primeiroJogador = new Jogador(nomePrimeiroJogador, pecasBrancas);
  this->segundoJogador = new Jogador(nomeSegundoJogador, pecasPretas);
}

void PartidaTradicional::iniciarPartida()
{
  if (this)
  {
    bool jogoEncerrado = false;
    bool turnoPrimeiroJogador = true;
    Jogador *jogadorAtual = nullptr;
    PecasPack *pecasJogadorAtual = nullptr;

    do
    {
      jogadorAtual = turnoPrimeiroJogador ? this->primeiroJogador : this->segundoJogador;

      this->tabuleiro->show(turnoPrimeiroJogador);
      pecasJogadorAtual = jogadorAtual->getPecas();

    } while (!jogoEncerrado);
  }
}

void PartidaTradicional::salvarPartida() {}
void PartidaTradicional::encerrarPartida() {}
