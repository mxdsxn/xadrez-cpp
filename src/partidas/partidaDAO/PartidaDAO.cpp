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
    int idNovoPrimeiroJogador = partida->getPrimeiroJogador()->salvar(idNovaPartida);
    int idNovoPacotePecaPrimeiroJogador = partida->getPrimeiroJogador()->getPacotePecas()->salvar(idNovoPrimeiroJogador);

    int idNovoSegundoJogador = partida->getSegundoJogador()->salvar(idNovaPartida);
    int idNovoPacotePecaSegundoJogador = partida->getSegundoJogador()->getPacotePecas()->salvar(idNovoSegundoJogador);

    return true;
  }
}
