#pragma once

#include "./Tabuleiro.h"
#include "./Controle.h"

class Principal
{
private:
  Tabuleiro *tabuleiroExibicao;
  Controle *controleJogo;
  int mostrarMenu();

public:
  Principal();
  void iniciar();
};
