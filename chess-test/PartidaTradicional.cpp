#include "./PartidaTradicional.h"
#include "./utils.h"
#include <iostream>

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
    std::cout << endl;
  }
}

Peca *PartidaTradicional::selecionarPecaDisponivel(bool primeiroJogador)
{
  int indicePecaSelecionada = 0;

  Jogador *jogadorAtual = primeiroJogador ? this->primeiroJogador : this->segundoJogador;
  PecasPack *pecasJogadorAtual = jogadorAtual->getPacotePecas();
  vector<vector<Posicao *>> *matrizPosicoesTabuleiro = this->tabuleiro->getTodasPosicoes();
  vector<Peca *> pecasDisponiveis = pecasJogadorAtual->getPecasDisponiveisJogadas(matrizPosicoesTabuleiro);
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

  clear();
  return pecaSelecionada;
}

bool PartidaTradicional::selecionarJogadasDisponiveis(Peca *pecaSelecionada)
{
  bool resultado = false;
  int indiceJogadaSelecionada = 0;
  vector<Posicao *> jogadasDisponiveis;
  vector<vector<Posicao *>> *matrizPosicoesTabuleiro = this->tabuleiro->getTodasPosicoes();
  Posicao *jogadaSelecionada = nullptr;

  // Envia para o pacote de pecas do adversario a peça selecionada, e assim, sao filtradas as jogadas que nao colocam o Rei em risco
  PecasPack *pecasJogadorAdversario = ((!pecaSelecionada->getSentidoPraFrente())
                                           ? this->primeiroJogador
                                           : this->segundoJogador)
                                          ->getPacotePecas();

  // Pede ao pacote de pecas adversario para verificar se algum movimentado da pecaSelecionada dará abertura para um Xeque
  jogadasDisponiveis = pecasJogadorAdversario->getJogadasDisponiveisFiltrandoRiscoXeque(pecaSelecionada);

  do
  {
    std::cout << "Selecione um das jogadas disponiveis para : "
              << pecaSelecionada->getPosicaoAtual()->showSimbolo()
              << " | "
              << formataCoordenadas(posicaoToCoordStr(pecaSelecionada->getPosicaoAtual()))
              << endl
              << endl;

    for (int indice = 0; indice < jogadasDisponiveis.size(); indice++)
    {
      Posicao *jogadaAtual = jogadasDisponiveis[indice];

      std::cout << (indice + 1)
                << " - "
                << formataCoordenadas(posicaoToCoordStr(jogadaAtual))
                << endl;
    }

    std::cout << endl;
    cin >> indiceJogadaSelecionada;
    cleanBuffer();
  } while (indiceJogadaSelecionada <= 0 || indiceJogadaSelecionada > jogadasDisponiveis.size());

  jogadaSelecionada = jogadasDisponiveis[indiceJogadaSelecionada - 1];

  resultado = pecaSelecionada->movimentar(jogadaSelecionada);

  clear();
  return resultado;
}

void mostrarJogadorRodadaAtual(Jogador *jogadorAtual)
{
  std::cout << "Turno de " << jogadorAtual->getNome()
            << endl
            << endl;
}

void PartidaTradicional::iniciarPartida()
{
  clear();
  if (this)
  {
    bool jogoEncerrado = false;
    bool turnoPrimeiroJogador = this->turnoPrimeiroJogador;

    Jogador *jogadorAtual = nullptr;
    Jogador *jogadorAdversario = nullptr;

    Peca *pecaSelecionada = nullptr;
    bool resultadoJogada = false;

    bool reiJogadorAtualEmXeque = false;
    bool reiJogadorAdversarioEmXeque = false;
    Posicao *posicaoReiJogadorAdversario = nullptr;

    do
    {
      turnoPrimeiroJogador = this->turnoPrimeiroJogador;
      jogadorAtual = turnoPrimeiroJogador ? this->primeiroJogador : this->segundoJogador;
      jogadorAdversario = turnoPrimeiroJogador ? this->segundoJogador : this->primeiroJogador;

      mostrarJogadorRodadaAtual(jogadorAtual);
      this->mostrarTabuleiro(turnoPrimeiroJogador);
      pecaSelecionada = this->selecionarPecaDisponivel(turnoPrimeiroJogador);

      mostrarJogadorRodadaAtual(jogadorAtual);
      this->mostrarTabuleiro(turnoPrimeiroJogador);
      resultadoJogada = this->selecionarJogadasDisponiveis(pecaSelecionada);

      mostrarJogadorRodadaAtual(jogadorAtual);
      this->mostrarTabuleiro(turnoPrimeiroJogador);

      if (resultadoJogada)
      {
        posicaoReiJogadorAdversario = jogadorAdversario->getPosicaoRei();
        reiJogadorAdversarioEmXeque = jogadorAtual->verificaReiAdversarioXeque(posicaoReiJogadorAdversario);
        if (reiJogadorAdversarioEmXeque)
        {
          jogadorAdversario->setXeque(true);
        }
        else
        {
          jogadorAdversario->setXeque(false);
        }
      }

      std::cout << "TECLE ENTER PARA ENCERRAR A JOGADA";

      cleanBuffer();

      this->turnoPrimeiroJogador = !turnoPrimeiroJogador;

      clear();
    } while (!jogoEncerrado);
  }
}

void PartidaTradicional::salvarPartida() {}
void PartidaTradicional::encerrarPartida() {}
