#include "./PecaDAO.h"

PecaDAO::PecaDAO()
{
  this->pecaSql = new PecaSql();
}

PecaDAO::~PecaDAO() {}

bool PecaDAO::salvar(int idPacotePeca, Peca *peca)
{
  Posicao *posicaoAtual = peca->getPosicaoAtual();

  int coordenadaY = posicaoAtual != nullptr ? posicaoAtual->getY() : -1;
  int coordenadaX = posicaoAtual != nullptr ? posicaoAtual->getX() : -1;

  int idNovaPeca = this->pecaSql->salvar(idPacotePeca,
                                         peca->getXeque(),
                                         peca->getSentidoPraFrente(),
                                         peca->getPrimeiraJogada(),
                                         coordenadaY,
                                         coordenadaX,
                                         peca->getCodigo());

  if (idNovaPeca == 0)
  {
    return false;
  }

  return true;
}