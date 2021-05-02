
#include <vector>
#include "./Peao.h"
#include "./PecasPack.h"
#include "./Posicao.h"

using namespace std;

class Peao;

class Tabuleiro
{
public:
  PecasPack *pecasJogador1 = nullptr;
  PecasPack *pecasJogador2 = nullptr;
  vector<vector<Posicao *>> posicoes;

  Tabuleiro();
  ~Tabuleiro();

  /**
     * @return Lista de Posições disponíveis.
     */
  vector<Posicao *> getPosicaoPecasDisponiveis(int jogador);

  /**
     * @return [VOID] Exibe o tabuleiro de xadrez e a disposição de peças.
     */
  void show(int jogador);

private:
  //vector<Posicao *> posicoes;
};
