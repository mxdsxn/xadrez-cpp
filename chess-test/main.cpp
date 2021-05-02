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

 tabuleiro->show(2);

 // procura peças disponiveis de um jogador
 vector<Posicao *> posicoesPecasDisponiveisJogador2 = tabuleiro->getPosicaoPecasDisponiveis(2);

 // monstra no console as peças e suas coordenadas para o jogador escolher a peça
 cout << "Pecas disponiveis: " << endl
      << endl;

 for (int i = 0; i < posicoesPecasDisponiveisJogador2.size(); i++)
 {
  Posicao *posicaoAtual = posicoesPecasDisponiveisJogador2[i];
  CoordenadasStr coordenadas = posicaoToCoordStr(*posicaoAtual);
  cout << " - " << posicaoAtual->showSimbolo() << " | " << formataCoordenadas(coordenadas) << endl;
 }

 // envia comando de movimentação
 Posicao *posi = posicoesPecasDisponiveisJogador2[1];

 return 0;
}