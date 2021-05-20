#include "./Jogador.h"

Jogador::Jogador(string nome, PecasPack *pecas)
{
  this->nome = nome;
  this->pecas = pecas;
  this->jogadorDAO = new JogadorDAO();
}

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
