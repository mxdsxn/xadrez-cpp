#pragma once

#include "./Partida.h"

class PartidaTradicional : public Partida
{
public:
  PartidaTradicional();
  void iniciarPartida();
  void salvarPartida();
  void encerrarPartida();
};
