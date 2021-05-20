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
    partida->getPrimeiroJogador()->salvar(idNovaPartida);
    partida->getSegundoJogador()->salvar(idNovaPartida);

    return true;
  }
}
