#pragma once

#include <string>
#include "../SqlConnection.h"

using namespace std;

/**
 * Responsavel por fazer integração com o banco responsável pela persistencia dos dados, diretamente com a tabela responsavel pela entidade Jogador
*/
class JogadorSql : public SqlConnection
{
public:
  JogadorSql();
  ~JogadorSql();

  /**
   * Cria um novo jogador no banco de dados
   * @param idPartida id da Partida criada no banco a qual o jogador está associado
   * @param emXeque Estado do jogador em relação ao xeque
   * @param nome Nome do jogador
   * @return 0 em casa de erro OU o Id da partida criada
  */
  int salvar(int idPartida, bool emXeque, string nome);
};