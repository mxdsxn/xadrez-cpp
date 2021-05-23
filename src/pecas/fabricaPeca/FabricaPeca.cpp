#include "./FabricaPeca.h"
#include "../pecaBispo/Bispo.h"
#include "../pecaCavalo/Cavalo.h"
#include "../pecaPeao/Peao.h"
#include "../pecaRainha/Rainha.h"
#include "../pecaRei/Rei.h"
#include "../pecaTorre/Torre.h"
#include <iostream>

using namespace std;

FabricaPeca::FabricaPeca() {}
FabricaPeca::~FabricaPeca() {}

Peca *FabricaPeca::criaPeca(string estilo, bool sentidoPraFrente, int codigoTipo)
{
  Peca *novaPeca = nullptr;
  switch (codigoTipo)
  {
  case 1:
    novaPeca = new Rei(estilo, sentidoPraFrente);
    break;

  case 2:
    novaPeca = new Rainha(estilo, sentidoPraFrente);
    break;
  case 3:
    novaPeca = new Cavalo(estilo, sentidoPraFrente);
    break;
  case 4:
    novaPeca = new Bispo(estilo, sentidoPraFrente);
    break;
  case 5:
    novaPeca = new Torre(estilo, sentidoPraFrente);
    break;
  case 6:
    novaPeca = new Peao(estilo, sentidoPraFrente);
    break;
  }
  return novaPeca;
}

Peca *FabricaPeca::recuperaPeca(int idPeca,
                                bool emXeque,
                                bool sentidoPraFrente,
                                bool primeiraJogada,
                                int codigoTipo,
                                int coordenada_x,
                                int coordenada_y)
{
  Peca *novaPeca = nullptr;
  switch (codigoTipo)
  {
  case 1:
    novaPeca = new Rei(idPeca,
                       emXeque,
                       sentidoPraFrente,
                       primeiraJogada,
                       coordenada_x,
                       coordenada_y);
    break;

  case 2:
    novaPeca = new Rainha(idPeca,
                          emXeque,
                          sentidoPraFrente,
                          primeiraJogada,
                          coordenada_x,
                          coordenada_y);
    break;
  case 3:
    novaPeca = new Cavalo(idPeca,
                          emXeque,
                          sentidoPraFrente,
                          primeiraJogada,
                          coordenada_x,
                          coordenada_y);
    break;
  case 4:
    novaPeca = new Bispo(idPeca,
                         emXeque,
                         sentidoPraFrente,
                         primeiraJogada,
                         coordenada_x,
                         coordenada_y);
    break;
  case 5:
    novaPeca = new Torre(idPeca,
                         emXeque,
                         sentidoPraFrente,
                         primeiraJogada,
                         coordenada_x,
                         coordenada_y);
    break;
  case 6:
    novaPeca = new Peao(idPeca,
                        emXeque,
                        sentidoPraFrente,
                        primeiraJogada,
                        coordenada_x,
                        coordenada_y);
    break;
  }

  return novaPeca;
}
