#pragma once

#include <string>
#include "../SqlConnection.h"

using namespace std;

/**
 * Responsavel por fazer integração com o banco responsável pela persistencia dos dados, diretamente com a tabela responsavel pela entidade PacotePecas
*/
class PacotePecasSql : public SqlConnection
{
public:
  PacotePecasSql();
  ~PacotePecasSql();

  /**
   * Cria um novo pacote de pecas no banco de dados
   * @param idJogador id do Jogador criado no banco a qual o pacote está associado
   * @param emXeque Estado do pacote em relação ao xeque
   * @param estilo Estilo das peças do pacote
   * @return 0 em casa de erro OU o Id do pacote criada
  */
  int salvar(int idJogador, bool emXeque, string estilo);
};
