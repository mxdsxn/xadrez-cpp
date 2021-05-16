#include "./principal/Principal.h"
#include "./utils/utils.h"

int main()
{
  clear();

  Principal *novoJogo = new Principal();

  novoJogo->iniciar();

  return 0;
}
