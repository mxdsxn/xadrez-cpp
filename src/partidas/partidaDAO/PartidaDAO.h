#pragma once

#include "../partidaBase/Partida.h"
#include "../../sqlConnection/partidaSql/PartidaSql.h"

class Partida;
class PartidaDAO
{
public:
  PartidaDAO();
  ~PartidaDAO();

  bool salvar(Partida *partida);

private:
  PartidaSql *partidaSql;
};
