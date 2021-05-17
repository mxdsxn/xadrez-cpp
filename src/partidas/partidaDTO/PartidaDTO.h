#pragma once
#include "../partidaBase/Partida.h"

class Partida;
class PartidaDTO
{
public:
  PartidaDTO();
  ~PartidaDTO();

  bool salvarPartida(Partida *partida);
};
