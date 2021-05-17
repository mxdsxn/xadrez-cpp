#include <iostream>
#include "./PartidaDTO.h"
#include "../../jogador/Jogador.h"
#include "../../posicao/Posicao.h"
#include "../../pacotePecas/PecasPack.h"
#include "../../utils/utils.h"

using namespace std;

PartidaDTO::PartidaDTO() {}
PartidaDTO::~PartidaDTO() {}

void exibeInfos(Jogador *jogador, PecasPack *pacotePecas, vector<Peca *> listaPecas)
{
  cout << "JOGADOR: " << jogador->getNome() << endl
       << "- em xeque: " << jogador->getXeque() << endl
       << endl;

  cout << "PACOTE DE PECAS:" << endl
       << "- estilo: " << pacotePecas->getEstilo() << endl
       << "- em xeque: " << pacotePecas->getXeque() << endl
       << endl;

  cout << "PECAS: " << listaPecas.size() - 1 << endl;
  for (int indice = 1; indice < listaPecas.size(); indice++)
  {
    Peca *pecaAtual = listaPecas[indice];

    cout << endl
         << "- simbolo: " << pecaAtual->getSimbolo() << endl
         << "- primeira jogada: " << pecaAtual->getPrimeiraJogada() << endl
         << "- sentido pra frente: " << pecaAtual->getSentidoPraFrente() << endl
         << "- em xeque: " << pecaAtual->getXeque() << endl
         << "- posicao Y: " << pecaAtual->getPosicaoAtual()->getY() << endl
         << "- posicao X: " << pecaAtual->getPosicaoAtual()->getX() << endl
         << endl;
  }

  cout << endl;
}

bool PartidaDTO::salvarPartida(Partida *partida)
{
  cout << "SALVAR PARTIDA" << endl;

  cout << "PARTIDA - turnoPrimeiroJogador: " << partida->getTurnoPrimeiroJogador() << endl
       << endl;

  partida->getTabuleiro()->show(true);

  //Primeiro jogador
  Jogador *primeiroJogador = partida->getPrimeiroJogador();
  PecasPack *pacotePrimeiroJogador = primeiroJogador->getPacotePecas();
  vector<Peca *> listaPecasPrimeiroJogador = pacotePrimeiroJogador->getTodasPecas();

  exibeInfos(primeiroJogador, pacotePrimeiroJogador, listaPecasPrimeiroJogador);
  cleanBuffer();

  partida->getTabuleiro()->show(false);

  //Seegundo jogador
  Jogador *segundoJogador = partida->getSegundoJogador();
  PecasPack *pacoteSegundoJogador = segundoJogador->getPacotePecas();
  vector<Peca *> listaPecasSegundoJogador = pacoteSegundoJogador->getTodasPecas();

  exibeInfos(segundoJogador, pacoteSegundoJogador, listaPecasSegundoJogador);
  cleanBuffer();

  return false;
}

/*
* PARTIDA
* - turnoPrimeiroJogador

* JOGADOR
* - emXeque
* - nome

* PECA
* - x
* - y
* - tipo de peca
* - sentidoPraFrente
* - primeiraJogada
* - emXeque

* PECASPACK
* - estilo
* - emXeque
*/
