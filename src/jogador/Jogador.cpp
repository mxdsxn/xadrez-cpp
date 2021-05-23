#include "./Jogador.h"
#include "../pacotePecas/pacotePecasDAO/PacotePecasDAO.h"
#include "../utils/utils.h"
#include <iostream>

using namespace std;

Jogador::Jogador(string nome, PecasPack *pecas)
{
  this->nome = nome;
  this->pecas = pecas;
  this->jogadorDAO = new JogadorDAO();
  this->sql_idJogador = -1;
}

Jogador::Jogador(int idJogador, bool emXeque, string nome)
{
  this->sql_idJogador = idJogador;
  this->emXeque = emXeque;
  this->jogadorDAO = new JogadorDAO();
  this->nome = nome;

  PacotePecasDAO *pacotePecasDAO = new PacotePecasDAO();
  vector<PecasPack *> listaPacotePecas = pacotePecasDAO->recuperar(idJogador);

  this->pecas = listaPacotePecas[0];
}

Jogador::~Jogador() {}

string Jogador::getNome()
{
  string nome;
  if (this)
  {
    nome = this->nome;
  }
  return nome;
}

PecasPack *Jogador::getPacotePecas()
{
  PecasPack *pecas;
  if (this)
  {
    pecas = this->pecas;
  }
  return pecas;
}

Posicao *Jogador::getPosicaoRei()
{
  if (this)
  {
    return this->pecas->getPosicaoRei();
  }
  return nullptr;
}

bool Jogador::verificaReiAdversarioXeque(Posicao *posicaoReiAdversario)
{
  if (this)
  {
    return this->pecas->verificaReiAdversarioXeque(posicaoReiAdversario);
  }
  return false;
}

void Jogador::setXeque(bool emXeque)
{
  if (this)
  {
    this->emXeque = emXeque;
    this->pecas->setXeque(emXeque);
  }
}

bool Jogador::getXeque()
{
  if (this)
  {
    return this->emXeque;
  }
  return false;
}

bool Jogador::verificaXequeMate(Jogador *adversario, vector<vector<Posicao *>> *posicoesTabuleiro)
{
  PecasPack *pecasAdversario = adversario->getPacotePecas();
  PecasPack *pecasJogador = this->getPacotePecas();

  vector<Peca *> listaPecasAdversario = pecasAdversario->getPecasDisponiveisJogadas(posicoesTabuleiro);

  for (int indice = 1; indice < listaPecasAdversario.size(); indice++)
  {
    Peca *pecaAtual = listaPecasAdversario[indice];
    // caso alguma peça consiga movimentar e tirar o rei adversario de xeque
    if (pecasJogador->getJogadasDisponiveisFiltrandoRiscoXeque(pecaAtual).size() > 0)
    {
      return false;
    }
  }

  return true;
}

int Jogador::salvar(int idPartida)
{
  if (this)
  {
    return this->jogadorDAO->salvar(idPartida, this);
  }

  return 0;
}

int Jogador::getSqlIdJogador()
{
  if (this)
  {
    return this->sql_idJogador;
  }
  return -1;
}
