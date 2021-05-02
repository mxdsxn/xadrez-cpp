#include "./Peao.h"
#include <iostream>

using namespace std;

Peao::Peao(string estilo) : Peca(estilo)
{
  this->simbolo = this->estilo == "preto" ? "♙" : "♟";
}
Peao::~Peao() {}

/*
vector<Posicao *> Peao::getPosicoesValidas()
{
    vector<Posicao *> posicoesValidas;
    cout << "[PEAO] - Metodo `getPosicoesValidas()" << endl;

    return posicoesValidas;
}*/

bool Peao::movimentar(Posicao *novaPosicao)
{
  if (this)
  {
    Posicao *antigaPosicao = this->posicao;

    /*
    * ainda é necessario fazer a remocao da peça que está na novaPosicao
    * essa remocao precisa acessar Tabuleiro>PackAdversario e remover a peça do jogo
    */

    antigaPosicao->setPeca(nullptr);
    novaPosicao->setPeca(this);
    this->setPosicao(novaPosicao);

    /*
    * ainda é necessario fazer a verificacao se o rei adversario está em cheque
    */
    return true;
  }
  cout << "[PEAO] - Metodo `movimentar()" << endl;
  return false;
}

bool Peao::setPosicao(Posicao *novaPosicao)
{
  if (this)
  {
    this->posicao = novaPosicao;
    return true;
  }
  cout << "[PEAO] - Metodo `movimentar()" << endl;
  return false;
}

bool Peao::verificaXequeAdversario(int xPosReiAdversario, int yPosReiAdversario)
{
  cout << "[PEAO] - Metodo `verificaXequeAdversario()" << endl;
  return false;
}
