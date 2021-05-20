#include "./PacotePecasDAO.h"

PacotePecasDAO::PacotePecasDAO()
{
  this->pacotePecasSql = new PacotePecasSql();
}

PacotePecasDAO::~PacotePecasDAO() {}

int PacotePecasDAO::salvar(int idJogador, PecasPack *pacotePecas)
{
  int PacotePecas = this->pacotePecasSql->salvar(idJogador, pacotePecas->getXeque(), pacotePecas->getEstilo());

  if (PacotePecas == 0)
  {
    return 0;
  }
  return PacotePecas;
}
