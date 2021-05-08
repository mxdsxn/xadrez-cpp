#include "./Principal.h"
#include "./clear.h"

int main()
{
  clear();

  Principal *novoJogo = new Principal();

  novoJogo->iniciar();

  return 0;
}
