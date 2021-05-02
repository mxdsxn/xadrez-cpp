#include "./Peca.h"

Peca::Peca(string estilo, bool sentidoJogador1)
{
  this->estilo = estilo;
  this->posicao = nullptr;
  this->sentidoJogador1 = sentidoJogador1;
}

Peca::~Peca()
{
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
