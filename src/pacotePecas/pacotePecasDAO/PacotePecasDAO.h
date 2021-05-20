#pragma once

#include "../PecasPack.h"
#include "../../sqlConnection/pacotePecasSql/PacotePecasSql.h"

class PecasPack;
class PacotePecasDAO
{
public:
  PacotePecasDAO();
  ~PacotePecasDAO();

  /**
   * Salva um pacotePecas e todos os seus estados
   * @param idJogador Id do jogador a qual o pacote de pecas está associado
   * @param pacotePecas Ponteiro do pacotePecas a ser salvo
   * @return 0 caso tenha ocorrido erro ao salvar OU id do pacotePecas no banco
  */
  int salvar(int idJogador, PecasPack *pacotePecas);

private:
  PacotePecasSql *pacotePecasSql;
};
