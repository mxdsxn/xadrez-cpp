#pragma once
#include "./Partida.h"
#include "./FabricaPartida.h"

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
