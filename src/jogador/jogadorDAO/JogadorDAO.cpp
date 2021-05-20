#include "./JogadorDAO.h"

JogadorDAO::JogadorDAO()
{
  this->jogadorSql = new JogadorSql();
}

JogadorDAO::~JogadorDAO() {}

int JogadorDAO::salvar(int idPartida, Jogador *jogador)
{
  int idNovoJogador = this->jogadorSql->salvar(idPartida, jogador->getXeque(), jogador->getNome());

  if (idNovoJogador == 0)
  {
    return false;
  }
  return idNovoJogador;
}
