#include "./PartidaDAO.h"

PartidaDAO::PartidaDAO()
{
  this->partidaSql = new PartidaSql();
}

PartidaDAO::~PartidaDAO() {}

bool PartidaDAO::salvar(Partida *partida)
{
  int idNovaPartida = this->partidaSql->salvar(partida->getTurnoPrimeiroJogador(), partida->getCodigoTipo());

  if (partida == 0)
  {
    return false;
  }
  else
  {
    // salvar outros dados da partida
  }
}
