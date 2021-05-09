#include <iostream>
#include <string>
#include "./Posicao.h"

#include "./utils.h"

void clear()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
  system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
  system("cls");
#endif
}

void cleanBuffer()
{
  std::string buffer;
  getline(std::cin, buffer);
}

CoordenadasStr posicaoToCoordStr(Posicao *posicao)
{
  CoordenadasStr coordenadasFormatadas;

  int x = posicao->getX();
  int y = posicao->getY();

  if ((x >= 0 && x < 8) && (y >= 0 && y < 8))
  {
    coordenadasFormatadas.y = to_string(y + 1);
    coordenadasFormatadas.x = (char)(x + 65);
  }

  return coordenadasFormatadas;
}

string formataCoordenadas(CoordenadasStr coordenadas)
{
  return "[" + coordenadas.x + ", " + coordenadas.y + "]";
}
