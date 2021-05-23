#pragma once

#include "../Jogador.h"
#include "../../sqlConnection/jogadorSql/JogadorSql.h"

class Jogador;
class JogadorSql;
class JogadorDAO
{
public:
  JogadorDAO();
  ~JogadorDAO();

  /**
   * Salva um jogador e todos os seus estados
   * @param idPartida id da partida no banco a qual o jogador está associado
   * @param jogador Ponteiro do jogador a ser salvo
   * @return 0 caso tenha ocorrido erro ao salvar OU id do jogador no banco
  */
  int salvar(int idPartida, Jogador *jogador);

  /**
   * Recuperar uma lista de Jogadores
   * @param idPartida id da Partida que os jogadores estão associado
   * @return Lista de Jogadores
  */
  vector<Jogador *> recuperar(int idPartida = -1);

  /**
   * Deleta um jogador e todos os seus estados
   * @param jogador Ponteiro do jogador a ser deletar
  */
  void deletar(Jogador *jogador);

private:
  JogadorSql *jogadorSql;
};
