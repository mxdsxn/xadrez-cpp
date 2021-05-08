#pragma once
#include <string>
#include "./PecasPack.h"

using namespace std;

class Jogador
{
private:
  string nome;
  PecasPack *pecas;

public:
  Jogador(string nome, PecasPack *pecas);
  string getNome();
  PecasPack *getPecas();
};
