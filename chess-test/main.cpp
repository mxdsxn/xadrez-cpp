#include "./Tabuleiro.h"
#include "./Posicao.h"

#include <iostream>
#include <vector>

using namespace std;

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
CoordenadasStr posicaoToCoordStr(Posicao &posicao)
{
  CoordenadasStr coordenadasFormatadas;

  int x = posicao.x;
  int y = posicao.y;

  if ((x >= 0 && x < 8) && (y >= 0 && y < 8))
  {
    coordenadasFormatadas.x = to_string(x + 1);
    coordenadasFormatadas.y = (char)(y + 65);
  }

  return coordenadasFormatadas;
}

string formataCoordenadas(CoordenadasStr coordenadas)
{
  return "[" + coordenadas.x + ", " + coordenadas.y + "]";
}

int main()
{
  Tabuleiro *tabuleiro = new Tabuleiro();

  tabuleiro->show(1);

  // procura peças disponiveis de um jogador
  vector<Posicao *> posicoesPecasDisponiveisJogador1 = tabuleiro->getPosicaoPecasDisponiveis(1);

  // mostra no console as peças e suas coordenadas para o jogador escolher a peça
  cout << "Pecas disponiveis: " << endl
       << endl;

  for (int i = 0; i < posicoesPecasDisponiveisJogador1.size(); i++)
  {
    Posicao *posicaoAtual = posicoesPecasDisponiveisJogador1[i];
    CoordenadasStr coordenadas = posicaoToCoordStr(*posicaoAtual);
    cout << " - " << posicaoAtual->showSimbolo() << " | " << formataCoordenadas(coordenadas) << endl;
  }

  Posicao *posi = posicoesPecasDisponiveisJogador1[1];
  Peca *peca = posi->pecaAtual;
  vector<Posicao *> posicoesDisponiveisPeca = peca->getPosicoesValidas(&tabuleiro->posicoes);

  tabuleiro->show(1);

  // mostra no console as peças e suas coordenadas para o jogador escolher a peça
  cout << "Posicoes disponiveis: " << endl
       << formataCoordenadas(posicaoToCoordStr(*(peca->posicao)))
       << endl;
  for (int i = 0; i < posicoesDisponiveisPeca.size(); i++)
  {
    Posicao *posicaoAtual = posicoesDisponiveisPeca[i];
    CoordenadasStr coordenadas = posicaoToCoordStr(*posicaoAtual);
    cout << " - " << posicaoAtual->showSimbolo() << " | " << formataCoordenadas(coordenadas) << endl;
  }

  // move a peca para a posicao desejada
  for (int i = 0; i < posicoesDisponiveisPeca.size(); i++)
  {
    Posicao *posicaoAtual = posicoesDisponiveisPeca[i];
    if (posicaoAtual->x == 0 && posicaoAtual->y == 2)
    {
      peca->movimentar(posicaoAtual);
    }
  }

  tabuleiro->show(1);

  posicoesPecasDisponiveisJogador1 = tabuleiro->getPosicaoPecasDisponiveis(1);
  posicoesDisponiveisPeca = peca->getPosicoesValidas(&tabuleiro->posicoes);
  // mostra no console as peças e suas coordenadas para o jogador escolher a peça
  cout << "Posicoes disponiveis: " << endl
       << formataCoordenadas(posicaoToCoordStr(*(peca->posicao)))
       << endl;
  for (int i = 0; i < posicoesDisponiveisPeca.size(); i++)
  {
    Posicao *posicaoAtual = posicoesDisponiveisPeca[i];
    CoordenadasStr coordenadas = posicaoToCoordStr(*posicaoAtual);
    cout << " - " << posicaoAtual->showSimbolo() << " | " << formataCoordenadas(coordenadas) << endl;
  }

  cout << "Rei está em cheque: " << (peca->verificaXequeAdversario(posicoesDisponiveisPeca[0], &tabuleiro->posicoes) ? "sim" : "nao") << endl;

  return 0;
}
