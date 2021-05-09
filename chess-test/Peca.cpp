#include "./Peca.h"

Peca::Peca(string estilo, bool sentidoPraFrente)
{
  this->estilo = estilo;
  this->posicao = nullptr;
  this->primeiraJogada = true;
  this->sentidoPraFrente = sentidoPraFrente;
  this->emXeque = false;
}

Peca::~Peca()
{
}

bool Peca::movimentar(Posicao *novaPosicao)
{
  if (this)
  {
    Posicao *antigaPosicao = this->posicao;

    novaPosicao->getPecaAtual()->removePosicao(); // desvincula nova posicao da peca capturada
    antigaPosicao->removePeca();                  // desvincula peça movimentada da antiga posicao
    novaPosicao->setPeca(this);                   // vincula peca movimentada à nova posicao
    this->setPosicao(novaPosicao);                // vincula nova posicao à peca movimentada
    this->primeiraJogada = false;                 // remove a flag de primeiraJogada do peao

    return true;
  }

  return false;
}

bool Peca::verificaXequeAdversario(Posicao *posicaoReiAdversario, vector<vector<Posicao *>> *posicoesTabuleiro)
{
  if (this)
  {
    vector<Posicao *> posicoesDisponiveisPeca = this->getPosicoesValidas(posicoesTabuleiro);

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

bool Peca::setPosicao(Posicao *novaPosicao)
{
  if (this)
  {
    this->posicao = novaPosicao;
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

Posicao *Peca::getPosicaoAtual()
{
  if (this)
  {
    return this->posicao;
  }

  return nullptr;
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

bool Peca::getSentidoPraFrente()
{
  if (this)
  {
    this->sentidoPraFrente;
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

bool Peca::getXeque()
{
  if (this)
  {
    return this->emXeque;
  }
  return false;
}

bool Peca::getCodigo()
{
  return this->codigo;
}
