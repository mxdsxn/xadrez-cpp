#pragma once

#include "../../partidas/fabricaPartida/FabricaPartida.h"
#include "../../partidas/partidaBase/Partida.h"
#include "../SqlConnection.h"
#include <vector>

using namespace std;

/**
 * Responsavel por fazer integração com o banco responsável pela persistencia dos dados, diretamente com a tabela responsavel pela entidade Partida
*/

class Partida;
class FabricaPartida;
class PartidaSql : public SqlConnection
{
public:
  PartidaSql();
  ~PartidaSql();

  /**
   * Cria uma nova partida no banco de dados
   * @param turnoPrimeiroJogador Estado da partida em relação ao turno
   * @param codigoTipo Tipo da partida para a recuperação dos dados
   * @return 0 em casa de erro OU o Id da partida criada
  */
  int salvar(bool turnoPrimeiroJogador, int codigoTipo, int sql_idPartida);

  /**
   * Recuperar uma lista de Partidas
   * @param idPartida caso essa partida seja a selecionada para jogar, nao obrigatoria caso queira recuperar todas as partidas disponiveis
   * @return Lista de partidas
  */
  vector<Partida *> recuperar(int idPartida = -1);
};
