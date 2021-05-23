#pragma once
#include "../pecaBase/Peca.h"

using namespace std;

class Peca;
class FabricaPeca
{
public:
  FabricaPeca();
  ~FabricaPeca();

  Peca *criaPeca(string estilo, bool sentidoPraFrente, int codigoTipo);
  Peca *recuperaPeca(int idPeca,
                     bool emXeque,
                     bool sentidoPraFrente,
                     bool primeiraJogada,
                     int codigoTipo,
                     int coordenada_x,
                     int coordenada_y);
};
