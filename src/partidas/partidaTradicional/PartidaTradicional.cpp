#include <iostream>
#include "./PartidaTradicional.h"
#include "../../utils/utils.h"

PartidaTradicional::PartidaTradicional(string nomePrimeiroJogador, string nomeSegundoJogador) : Partida()
{
  PecasPack *pecasBrancas = this->tabuleiro->getPecasBrancas();
  PecasPack *pecasPretas = this->tabuleiro->getPecasPretas();

  this->primeiroJogador = new Jogador(nomePrimeiroJogador, pecasBrancas);
  this->segundoJogador = new Jogador(nomeSegundoJogador, pecasPretas);
  this->turnoPrimeiroJogador = true;
  this->codigoTipo = TipoPartida::Tradicional;
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

    std::cout << endl
              << "0 - Pausar"
              << endl;
    cin >> indicePecaSelecionada;
    cleanBuffer();

  } while (indicePecaSelecionada < 0 || indicePecaSelecionada > pecasDisponiveis.size());

  if (indicePecaSelecionada != 0)
  {
    pecaSelecionada = pecasDisponiveis[indicePecaSelecionada - 1];
  }
  else
  {
    pecaSelecionada = nullptr;
  }

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
              << pecaSelecionada->getSimbolo()
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

    std::cout << endl
              << "0 - Voltar"
              << endl;
    cin >> indiceJogadaSelecionada;
    cleanBuffer();
  } while (indiceJogadaSelecionada < 0 || indiceJogadaSelecionada > jogadasDisponiveis.size());

  if (indiceJogadaSelecionada != 0)
  {

    jogadaSelecionada = jogadasDisponiveis[indiceJogadaSelecionada - 1];
    resultado = pecaSelecionada->movimentar(jogadaSelecionada);
  }
  else
  {
    resultado = false;
  }

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
    bool salvarJogo = false;
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

      if (pecaSelecionada)
      {
        mostrarJogadorRodadaAtual(jogadorAtual);
        this->mostrarTabuleiro(turnoPrimeiroJogador);
        resultadoJogada = this->selecionarJogadasDisponiveis(pecaSelecionada);

        if (resultadoJogada)
        {
          mostrarJogadorRodadaAtual(jogadorAtual);
          this->mostrarTabuleiro(turnoPrimeiroJogador);

          if (resultadoJogada)
          {
            posicaoReiJogadorAdversario = jogadorAdversario->getPosicaoRei();
            reiJogadorAdversarioEmXeque = jogadorAtual->verificaReiAdversarioXeque(posicaoReiJogadorAdversario);
            if (reiJogadorAdversarioEmXeque)
            {
              jogadorAdversario->setXeque(true);

              std::cout << jogadorAtual->getNome()
                        << " colocou "
                        << jogadorAdversario->getNome()
                        << " em xeque!"
                        << std::endl
                        << std::endl;

              bool xequeMate = jogadorAtual->verificaXequeMate(jogadorAdversario, this->tabuleiro->getTodasPosicoes());
              if (xequeMate)
              {
                std::cout << "XEQUE MATE!!" << std::endl;
                jogoEncerrado = true;
              }
            }
            else
            {
              jogadorAdversario->setXeque(false);
            }
          }

          std::cout << "TECLE ENTER PARA ENCERRAR A JOGADA";

          cleanBuffer();

          this->turnoPrimeiroJogador = !turnoPrimeiroJogador;
        }
      }

      if (pecaSelecionada == nullptr)
      {
        int menuOption = 0;
        do
        {
          this->mostrarTabuleiro(this->turnoPrimeiroJogador);

          mostrarJogadorRodadaAtual(jogadorAtual);
          cout << "Selecione uma opção para a partida atual: " << endl
               << " 1 - Continuar" << endl
               << " 2 - Salvar" << endl
               << endl;

          cin >> menuOption;
          cleanBuffer();

          switch (menuOption)
          {
          case 1:
            break;
          case 2:
            salvarJogo = true;
            break;
          default:
            break;
          }
        } while (menuOption != 1 && menuOption != 2);
      }

      clear();

    } while (!jogoEncerrado && !salvarJogo);

    if (salvarJogo)
    {
      //this->partidaDAO->salvarPartida(this);
    }
  }
}

void PartidaTradicional::salvarPartida() {}
void PartidaTradicional::encerrarPartida() {}
