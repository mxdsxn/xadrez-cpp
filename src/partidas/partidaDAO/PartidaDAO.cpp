#include "./PartidaDAO.h"

PartidaDAO::PartidaDAO()
{
  this->partidaSql = new PartidaSql();
}

PartidaDAO::~PartidaDAO() {}

bool PartidaDAO::salvar(Partida *partida)
{
  return this->partidaSql->salvar(partida->getTurnoPrimeiroJogador(), partida->getCodigoTipo());
}
