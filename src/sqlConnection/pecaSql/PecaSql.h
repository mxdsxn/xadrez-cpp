#pragma once

#include "../../pecas/pecaBase/Peca.h"
#include "../../pecas/fabricaPeca/FabricaPeca.h"
#include "../SqlConnection.h"
#include <vector>

using namespace std;

class Peca;
class FabricaPeca;

/**
 * Responsavel por fazer integração com o banco responsável pela persistencia dos dados, diretamente com a tabela responsavel pela entidade peca
*/
class PecaSql : public SqlConnection
{
public:
  PecaSql();
  ~PecaSql();

  /**
   * Cria uma nova peca no banco de dados
   * @param idPacotePecas id do pacote o qual a peca esta associado
   * @param emXeque estado atual em relacao ao xeque
   * @param sentidoPraFrente sentido em que a peca se movimenta
   * @param primeiraJogada estado atual da sua primeira jogada
   * @param coordenada_y coordenada Y da posicao associada
   * @param coordenada_x cooddenada X da posicao associada
   * @param codigoTipo Tipo da peca para a recuperação dos dados
   * @return 0 em casa de erro OU o Id da peca criada
  */
  int salvar(
      int idPacotePecas,
      bool emXeque,
      bool sentidoPraFrente,
      bool primeiraJogada,
      int coordenada_y,
      int coordenada_x,
      int codigoTipo,
      int sql_idPeca);

  /**
   * Recuperar uma lista de Pecas
   * @param idPacotePeca id do pacote que as pecas estão associado
   * @return Lista de Pecas
  */
  vector<Peca *> recuperar(int idPacotePeca = -1);

  /**
   * Deleta uma peca e todos os seus estados
   * @param idPeca id da peca no banco
  */
  void deletar(int idPeca);
};
