#pragma once

#include "../tabuleiro/Tabuleiro.h"
#include "../controle/Controle.h"

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
