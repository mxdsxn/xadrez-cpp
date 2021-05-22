#include "./PartidaDAO.h"

PartidaDAO::PartidaDAO()
{
  this->partidaSql = new PartidaSql();
}

PartidaDAO::~PartidaDAO() {}

bool PartidaDAO::salvar(Partida *partida)
{
  int idNovaPartida = this->partidaSql->salvar(partida->getTurnoPrimeiroJogador(), partida->getCodigoTipo());

  if (partida == 0)
  {
    return false;
  }
  else
  {
    Jogador *primeiroJogador = partida->getPrimeiroJogador();
    Jogador *segundoJogador = partida->getSegundoJogador();

    int idNovoPrimeiroJogador = primeiroJogador->salvar(idNovaPartida);
    int idNovoSegundoJogador = segundoJogador->salvar(idNovaPartida);

    if (idNovoPrimeiroJogador == 0 || idNovoSegundoJogador == 0)
    {
      return false;
    }
    else
    {
      PecasPack *pacotePecasPrimeiroJogador = primeiroJogador->getPacotePecas();
      PecasPack *pacotePecasSegundoJogador = segundoJogador->getPacotePecas();

      int idNovoPacotePecaPrimeiroJogador = pacotePecasPrimeiroJogador->salvar(idNovoPrimeiroJogador);
      int idNovoPacotePecaSegundoJogador = pacotePecasSegundoJogador->salvar(idNovoSegundoJogador);

      if (idNovoPacotePecaPrimeiroJogador == 0 || idNovoPacotePecaSegundoJogador == 0)
      {
        return false;
      }
      else
      {
        vector<Peca *> pecasPrimeiroJogador = pacotePecasPrimeiroJogador->getTodasPecas();
        vector<Peca *> pecasSegundoJogador = pacotePecasSegundoJogador->getTodasPecas();

        for (int indice = 0; indice < pecasPrimeiroJogador.size(); indice++)
        {
          Peca *pecaAtualPrimeiroJogador = pecasPrimeiroJogador[indice];
          Peca *pecaAtualSegundoJogador = pecasSegundoJogador[indice];

          int idNovaPecaPrimeiroJogador = pecaAtualPrimeiroJogador->salvar(idNovoPacotePecaPrimeiroJogador);
          int idNovaPecaSegundoJogador = pecaAtualSegundoJogador->salvar(idNovoPacotePecaSegundoJogador);

          if (idNovaPecaSegundoJogador == 0 || idNovaPecaSegundoJogador == 0)
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
