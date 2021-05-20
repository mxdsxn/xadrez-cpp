#pragma once

#include "../Jogador.h"
#include "../../sqlConnection/jogadorSql/JogadorSql.h"

class Jogador;
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

private:
  JogadorSql *jogadorSql;
};
