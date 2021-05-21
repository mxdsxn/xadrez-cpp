#pragma once

#include "../pecaBase/Peca.h"
#include "../../sqlConnection/pecaSql/PecaSql.h"

class Peca;
class PecaDAO
{
public:
  PecaDAO();
  ~PecaDAO();

  /**
   * Salva uma peca e todos os seus estados
   * @param idPacotePeca id do pacote o qual a peca esta associado
   * @param peca Ponteiro da peca a ser salva
   * @return TRUE quando a peca é salva com sucesso
  */
  bool salvar(int idPacotePeca, Peca *peca);

private:
  PecaSql *pecaSql;
};
