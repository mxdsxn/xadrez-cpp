#pragma once

#include "../SqlConnection.h"

/**
 * Responsavel por fazer integração com o banco responsável pela persistencia dos dados, diretamente com a tabela responsavel pela entidade Partida
*/
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
  int salvar(bool turnoPrimeiroJogador, int codigoTipo);
};
