#include "../../utils/utils.h"
#include "./PartidaDAO.h"
#include <iostream>

PartidaDAO::PartidaDAO()
{
  this->partidaSql = new PartidaSql();
}

PartidaDAO::~PartidaDAO() {}

bool PartidaDAO::salvar(Partida *partida)
{
  int idNovaPartida = this->partidaSql->salvar(partida->getTurnoPrimeiroJogador(), partida->getCodigoTipo(), partida->getSqlIdPartida());

  if (partida == 0)
  {
    return false;
  }
  else
  {
    Jogador *primeiroJogador = partida->getPrimeiroJogador();
    Jogador *segundoJogador = partida->getSegundoJogador();

    idNovaPartida = idNovaPartida == -1 ? partida->getSqlIdPartida() : idNovaPartida;

    int idNovoPrimeiroJogador = primeiroJogador->salvar(idNovaPartida);
    int idNovoSegundoJogador = segundoJogador->salvar(idNovaPartida);

    if ((idNovoPrimeiroJogador == 0 || idNovoSegundoJogador == 0) && (primeiroJogador->getSqlIdJogador() == -1 && segundoJogador->getSqlIdJogador() == -1))
    {
      return false;
    }
    else
    {
      PecasPack *pacotePecasPrimeiroJogador = primeiroJogador->getPacotePecas();
      PecasPack *pacotePecasSegundoJogador = segundoJogador->getPacotePecas();

      idNovoPrimeiroJogador = idNovoPrimeiroJogador == -1 ? primeiroJogador->getSqlIdJogador() : idNovoPrimeiroJogador;
      idNovoSegundoJogador = idNovoSegundoJogador == -1 ? segundoJogador->getSqlIdJogador() : idNovoSegundoJogador;

      int idNovoPacotePecaPrimeiroJogador = pacotePecasPrimeiroJogador->salvar(idNovoPrimeiroJogador);
      int idNovoPacotePecaSegundoJogador = pacotePecasSegundoJogador->salvar(idNovoSegundoJogador);

      if ((idNovoPacotePecaPrimeiroJogador == 0 || idNovoPacotePecaSegundoJogador == 0) && (pacotePecasPrimeiroJogador->getSqlIdPacotePeca() == -1 && pacotePecasSegundoJogador->getSqlIdPacotePeca() == -1))
      {
        return false;
      }
      else
      {
        vector<Peca *> pecasPrimeiroJogador = pacotePecasPrimeiroJogador->getTodasPecas();
        vector<Peca *> pecasSegundoJogador = pacotePecasSegundoJogador->getTodasPecas();

        idNovoPacotePecaPrimeiroJogador = idNovoPacotePecaPrimeiroJogador == -1 ? pacotePecasPrimeiroJogador->getSqlIdPacotePeca() : idNovoPacotePecaPrimeiroJogador;
        idNovoPacotePecaSegundoJogador = idNovoPacotePecaSegundoJogador == -1 ? pacotePecasSegundoJogador->getSqlIdPacotePeca() : idNovoPacotePecaSegundoJogador;

        for (int indice = 0; indice < pecasPrimeiroJogador.size(); indice++)
        {
          Peca *pecaAtualPrimeiroJogador = pecasPrimeiroJogador[indice];
          Peca *pecaAtualSegundoJogador = pecasSegundoJogador[indice];

          int idNovaPecaPrimeiroJogador = pecaAtualPrimeiroJogador->salvar(idNovoPacotePecaPrimeiroJogador);
          int idNovaPecaSegundoJogador = pecaAtualSegundoJogador->salvar(idNovoPacotePecaSegundoJogador);

          if ((idNovaPecaSegundoJogador == 0 || idNovaPecaSegundoJogador == 0) && (pecaAtualPrimeiroJogador->getSqlIdPeca() == -1 && pecaAtualSegundoJogador->getSqlIdPeca() == -1))
          {
            return false;
          }
        }
      }
    }

    return true;
  }
}

vector<Partida *> PartidaDAO::recuperar(int idPartida)
{
  return this->partidaSql->recuperar(idPartida);
}

void PartidaDAO::deletar(Partida *partida)
{
  this->partidaSql->deletar(partida->getSqlIdPartida());
}
