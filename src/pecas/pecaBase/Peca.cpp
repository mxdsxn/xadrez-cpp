#include "./Peca.h"

Peca::Peca(string estilo, bool sentidoPraFrente)
{
  this->estilo = estilo;
  this->posicao = nullptr;
  this->primeiraJogada = true;
  this->sentidoPraFrente = sentidoPraFrente;
  this->emXeque = false;
  this->pecaDAO = new PecaDAO();
  this->sql_idPeca = -1;
}

Peca::Peca(int idPeca)
{
  this->sql_idPeca = idPeca;
  this->pecaDAO = new PecaDAO();
}

Peca::~Peca() {}

bool Peca::getXeque()
{
  if (this)
  {
    return this->emXeque;
  }
  return false;
}

bool Peca::getPrimeiraJogada()
{
  if (this)
  {
    return this->primeiraJogada;
  }
  return false;
}

int Peca::getCodigo()
{
  return this->codigo;
}

string Peca::getEstilo()
{
  if (this)
  {
    return this->estilo;
  }
  return "";
}

string Peca::getSimbolo()
{
  if (this)
  {
    return this->simbolo;
  }
  return "";
}

Posicao *Peca::getPosicaoAtual()
{
  if (this)
  {
    return this->posicao;
  }

  return nullptr;
}

bool Peca::getSentidoPraFrente()
{
  if (this)
  {
    return this->sentidoPraFrente;
  }
  return false;
}

void Peca::setXeque(bool emXeque)
{
  if (this)
  {
    this->emXeque = false;
  }
}

bool Peca::setPosicao(Posicao *novaPosicao)
{
  if (this)
  {
    this->posicao = novaPosicao;
    return true;
  }

  return false;
}

bool Peca::movimentar(Posicao *novaPosicao, bool simulacao)
{
  if (this)
  {
    Posicao *antigaPosicao = this->posicao;

    novaPosicao->getPecaAtual()->removePosicao(); // desvincula nova posicao da peca capturada
    antigaPosicao->removePeca();                  // desvincula peça movimentada da antiga posicao
    novaPosicao->setPeca(this);                   // vincula peca movimentada à nova posicao
    this->setPosicao(novaPosicao);                // vincula nova posicao à peca movimentada

    if (!simulacao)
      this->primeiraJogada = false; // remove a flag de primeiraJogada da peca caso nao seja uma simulacao de jogada

    return true;
  }

  return false;
}

bool Peca::removePosicao()
{
  if (this)
  {
    this->posicao = nullptr;
    return true;
  }

  return false;
}

bool Peca::verificaReiAdversarioXeque(Posicao *posicaoReiAdversario, vector<vector<Posicao *>> *posicoesTabuleiro)
{
  if (this)
  {
    vector<Posicao *> posicoesDisponiveisPeca = this->getTodasJogadasDisponiveis(posicoesTabuleiro);

    for (int i = 0; i < posicoesDisponiveisPeca.size(); i++)
    {
      Posicao *posicaoAtual = posicoesDisponiveisPeca[i];
      if (posicaoAtual == posicaoReiAdversario)
      {
        return true;
      }
    }
  }
  return false;
}

bool Peca::verificaDisponibilidadeMovimentar(vector<vector<Posicao *>> *posicoesTabuleiro)
{
  if (this)
  {
    int numeroJogadasDisponiveis = this->getTodasJogadasDisponiveis(posicoesTabuleiro).size();
    if (numeroJogadasDisponiveis > 0)
    {
      return true;
    }
  }

  return false;
}

int Peca::salvar(int idPacotePeca)
{
  if (this)
  {
    return this->pecaDAO->salvar(idPacotePeca, this);
  }
  return false;
}

void Peca::deletar()
{
  if (this->sql_idPeca != -1)
  {
    this->pecaDAO->deletar(this);
  }
}

int Peca::getSqlIdPeca()
{
  if (this)
  {
    return this->sql_idPeca;
  }
  return -1;
}
