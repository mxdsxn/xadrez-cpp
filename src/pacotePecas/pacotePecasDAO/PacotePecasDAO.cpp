#include "./PacotePecasDAO.h"

PacotePecasDAO::PacotePecasDAO()
{
  this->pacotePecasSql = new PacotePecasSql();
}

PacotePecasDAO::~PacotePecasDAO() {}

int PacotePecasDAO::salvar(int idJogador, PecasPack *pacotePecas)
{
  int PacotePecas = this->pacotePecasSql->salvar(idJogador, pacotePecas->getXeque(), pacotePecas->getEstilo(), pacotePecas->getSqlIdPacotePeca());

  if (PacotePecas == 0)
  {
    return 0;
  }
  return PacotePecas;
}

vector<PecasPack *> PacotePecasDAO::recuperar(int idJogador)
{
  return this->pacotePecasSql->recuperar(idJogador);
}

void PacotePecasDAO::deletar(PecasPack *pacotePeca)
{
  this->pacotePecasSql->deletar(pacotePeca->getSqlIdPacotePeca());
}
