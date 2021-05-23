#include <iostream>
#include <string>
#include "./Tabuleiro.h"
#include "../utils/utils.h"

using namespace std;

/**
 * Mostra no console a regua numerica que legenda o tabuleiro
 */
void legendaLetras(bool sentidoFrente)
{
  cout << " ";
  for (int i = sentidoFrente ? 0 : 7;
       sentidoFrente ? i <= 7 : i >= 0;
       sentidoFrente ? i++ : i--)
  {
    cout << " " << (char)(i + 65);
  }
  cout << endl;
}

Tabuleiro::Tabuleiro()
{
  // instancia pacote de peças para 2 jogadores
  this->pecasBrancas = new PecasPack("branco", true, this);
  this->pecasPretas = new PecasPack("preto", false, this);

  bool posicaoPreta = false;

  // instancia os posicoes do tabuleiro numa matriz
  for (int y = 0; y < 8; y++)
  {
    vector<Posicao *> novaLinha;

    for (int x = 0; x < 8; x++)
    {
      Posicao *novoPosicao = new Posicao(x, y, posicaoPreta);
      novaLinha.push_back(novoPosicao);

      posicaoPreta = !posicaoPreta;
    }
    posicaoPreta = !posicaoPreta;
    this->matrizPosicoes.push_back(novaLinha);
  }

  // coloca as pecas da realeza do primeiroJogador nas posicoes iniciais
  vector<Posicao *> *posicaoInicialRealezaPrimeiroJogador = &(this->matrizPosicoes[0]);
  this->pecasBrancas->setPosicaoInicialRealeza(posicaoInicialRealezaPrimeiroJogador);

  // coloca as peoes do primeiroJogador nas posicoes iniciais
  vector<Posicao *> *posicaoInicialPeoesPrimeiroJogador = &(this->matrizPosicoes[1]);
  this->pecasBrancas->setPosicaoInicialPeoes(posicaoInicialPeoesPrimeiroJogador);

  // coloca as pecas da realeza do segundoJogador nas posicoes iniciais
  vector<Posicao *> *posicaoInicialRealezaSegundoJogador = &(this->matrizPosicoes[7]);
  this->pecasPretas->setPosicaoInicialRealeza(posicaoInicialRealezaSegundoJogador);

  // coloca as peoes do segundoJogador nas posicoes iniciais
  vector<Posicao *> *posicaoInicialPeoesSegundoJogador = &(this->matrizPosicoes[6]);
  this->pecasPretas->setPosicaoInicialPeoes(posicaoInicialPeoesSegundoJogador);
}

Tabuleiro::Tabuleiro(PecasPack *pecasBrancas, PecasPack *pecasPretas)
{

  this->pecasBrancas = pecasBrancas;
  this->pecasPretas = pecasPretas;

  bool posicaoPreta = false;

  // instancia os posicoes do tabuleiro numa matriz
  for (int y = 0; y < 8; y++)
  {
    vector<Posicao *> novaLinha;

    for (int x = 0; x < 8; x++)
    {
      Posicao *novoPosicao = new Posicao(x, y, posicaoPreta);
      novaLinha.push_back(novoPosicao);

      posicaoPreta = !posicaoPreta;
    }
    posicaoPreta = !posicaoPreta;
    this->matrizPosicoes.push_back(novaLinha);
  }

  vector<Peca *> todasPecasBrancas = this->pecasBrancas->getTodasPecas();
  for (int indice = 0; indice < todasPecasBrancas.size(); indice++)
  {
    Peca *pecaAtual = todasPecasBrancas[indice];
    Posicao *posicaoAtualPeca = pecaAtual->getPosicaoAtual();

    int coordenadaX = posicaoAtualPeca->getX(), coordenadaY = posicaoAtualPeca->getY();
    if ((coordenadaY >= 0 && coordenadaY < 8) && (coordenadaX >= 0 && coordenadaX < 8))
    {
      Posicao *novaPosicao = this->matrizPosicoes[coordenadaY][coordenadaX];

      novaPosicao->setPeca(pecaAtual);
      pecaAtual->setPosicao(novaPosicao);
    }
    else
    {
      pecaAtual->setPosicao(nullptr);
    }
  }

  vector<Peca *> todasPecasPretas = this->pecasPretas->getTodasPecas();
  for (int indice = 0; indice < todasPecasPretas.size(); indice++)
  {
    Peca *pecaAtual = todasPecasPretas[indice];
    Posicao *posicaoAtualPeca = pecaAtual->getPosicaoAtual();

    int coordenadaX = posicaoAtualPeca->getX(), coordenadaY = posicaoAtualPeca->getY();
    if ((coordenadaY >= 0 && coordenadaY < 8) && (coordenadaX >= 0 && coordenadaX < 8))
    {
      Posicao *novaPosicao = this->matrizPosicoes[coordenadaY][coordenadaX];

      novaPosicao->setPeca(pecaAtual);
      pecaAtual->setPosicao(novaPosicao);
    }
    else
    {
      pecaAtual->setPosicao(nullptr);
    }
  }
}

Tabuleiro ::~Tabuleiro() {}

void Tabuleiro::show(bool sentidoFrente, bool mostrarLegenda)
{
  if (mostrarLegenda)
    legendaLetras(sentidoFrente);

  // Letra da legenda - ASCII
  int legendaNumerica = sentidoFrente ? 8 : 1;

  int linhaInicial = sentidoFrente ? this->matrizPosicoes.size() - 1 : 0;
  int linhaFinal = sentidoFrente ? 0 : this->matrizPosicoes.size() - 1;

  // esse logica usando o paramentro 'jogador' define qual o lado do tabuleiro sera apresentado
  for (int y = linhaInicial;
       sentidoFrente ? y >= linhaFinal : y <= linhaFinal;
       sentidoFrente ? y-- : y++)
  {
    vector<Posicao *> linhaAtual = this->matrizPosicoes[y];

    if (mostrarLegenda)
      cout << legendaNumerica;

    int inicioLinha = sentidoFrente ? 0 : linhaAtual.size() - 1;
    int finalLinha = sentidoFrente ? linhaAtual.size() - 1 : 0;

    for (int x = inicioLinha;
         sentidoFrente ? x <= finalLinha : x >= finalLinha;
         sentidoFrente ? x++ : x--)
    {
      Posicao *posicaoAtual = linhaAtual[x];
      cout << " " << posicaoAtual->showPosicao();
    }

    if (mostrarLegenda)
      cout << " "
           << legendaNumerica;

    cout << endl;

    sentidoFrente
        ? legendaNumerica--
        : legendaNumerica++;
  }

  if (mostrarLegenda)
    legendaLetras(sentidoFrente);
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
