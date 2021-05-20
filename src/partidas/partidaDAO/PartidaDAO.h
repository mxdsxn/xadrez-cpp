#pragma once

#include "../partidaBase/Partida.h"
#include "../../sqlConnection/partidaSql/PartidaSql.h"

class Partida;
class PartidaDAO
{
public:
  PartidaDAO();
  ~PartidaDAO();

  /**
   * Salva uma partida e todos os seus estados
   * @param partida Ponteiro da partida a ser salva
   * @return TRUE quando a partida é salva com sucesso
  */
  bool salvar(Partida *partida);

private:
  PartidaSql *partidaSql;
};
