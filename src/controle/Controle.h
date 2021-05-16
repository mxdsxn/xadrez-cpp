#pragma once
#include "../partidas/partidaBase/Partida.h"
#include "../partidas/fabricaPartida/FabricaPartida.h"

class Controle
{
private:
  Partida *partidaAtual;
  FabricaPartida *fabricaPartida;

  int mostrarMenuNovoJogo();

public:
  Controle();
  void novoJogo();
};
