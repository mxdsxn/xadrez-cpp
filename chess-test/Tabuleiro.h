
#include <vector>
#include "./Peao.h"
#include "./PecasPack.h"
#include "./Posicao.h"

using namespace std;

class Peao;

class Tabuleiro
{

private:
  vector<vector<Posicao *>> matrizPosicoes;
  PecasPack *pecasBrancas = nullptr;
  PecasPack *pecasPretas = nullptr;

public:
  Tabuleiro();
  ~Tabuleiro();

  /**
     * @param jogador Jogador atual no turno
     * @return Lista de Posições disponíveis.
     */
  vector<Posicao *> getPosicaoPecasDisponiveis(int jogador);

  /**
     * @param jogador Jogador atual no turno
     * @return [VOID] Exibe o tabuleiro de xadrez e a disposição de peças.
     */
  void show(int jogador);

  /**
     * @return Ponteiro para a matriz de posicoes do tabuleiro.
     */
  vector<vector<Posicao *>> *getTodasPosicoes();

  /**
     * @return Ponteiro para pacote de pecas Brancas.
     */
  PecasPack *getPecasBrancas();

  /**
     * @return Ponteiro para pacote de pecas sPretas.
     */
  PecasPack *getPecasPretas();
};
