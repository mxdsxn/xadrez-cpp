#include "./JogadorDAO.h"

JogadorDAO::JogadorDAO()
{
  this->jogadorSql = new JogadorSql();
}

JogadorDAO::~JogadorDAO() {}

int JogadorDAO::salvar(int idPartida, Jogador *jogador)
{
  int idNovoJogador = this->jogadorSql->salvar(idPartida, jogador->getXeque(), jogador->getNome(), jogador->getSqlIdJogador());

  if (idNovoJogador == 0)
  {
    return 0;
  }
  return idNovoJogador;
}

vector<Jogador *> JogadorDAO::recuperar(int idPartida)
{
  return this->jogadorSql->recuperar(idPartida);
}

void JogadorDAO::deletar(Jogador *jogador)
{
  this->jogadorSql->deletar(jogador->getSqlIdJogador());
}
