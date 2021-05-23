#pragma once

#include "../partidaBase/Partida.h"
#include "../../sqlConnection/partidaSql/PartidaSql.h"

class Partida;
class PartidaSql;
class PartidaDAO
{
public:
  PartidaDAO();
  ~PartidaDAO();

  /**
   * Salva uma partida e todos os seus estados
   * @param partida Ponteiro da partida a ser salva
   * @return TRUE quando a partida é salva com sucesso
  */
  bool salvar(Partida *partida);

  /**
   * Recuperar uma lista de Partidas
   * @param idPartida caso essa partida seja a selecionada para jogar, nao obrigatoria caso queira recuperar todas as partidas disponiveis
   * @return Lista de partidas
  */
  vector<Partida *> recuperar(int idPartida = -1);

  /**
   * Deleta uma partida e todos os seus estados
   * @param partida Ponteiro da partida a ser deletar
  */
  void deletar(Partida *partida);

private:
  PartidaSql *partidaSql;
};
