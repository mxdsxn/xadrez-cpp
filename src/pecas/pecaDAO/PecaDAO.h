#pragma once

#include "../pecaBase/Peca.h"
#include "../../sqlConnection/pecaSql/PecaSql.h"
#include <vector>

using namespace std;

class Peca;
class PecaSql;

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

  /**
   * Recuperar uma lista de Pecas
   * @param idPacotePeca id do pacote que as pecas estão associado
   * @return Lista de Pecas
  */
  vector<Peca *> recuperar(int idPacotePeca = -1);

private:
  PecaSql *pecaSql;
};
