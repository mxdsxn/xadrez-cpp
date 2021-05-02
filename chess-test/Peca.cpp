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
