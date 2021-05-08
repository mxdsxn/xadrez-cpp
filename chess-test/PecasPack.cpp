#include "PecasPack.h"
#include "./Peao.h"

PecasPack::PecasPack(string estilo, bool sentidoPraFrente)
{
  this->estilo = estilo;

  // instancia os peoes
  for (int i = 1; i <= 8; i++)
  {
    Peao *novoPeao = new Peao(estilo, sentidoPraFrente);
    this->peoes.push_back(novoPeao);
  }

  /*
    // instancia os torres
    for (int i = 1; i <= 2; i++)
    {
        Torre *novaTorre = new Torre(estilo);
        this->torres.push_back(novaTorre);
    }

    // instancia os bispos
    for (int i = 1; i <= 2; i++)
    {
        Bispo *novoBispo = new Bispo(estilo);
        this->bispos.push_back(novoBispo);
    }

    // instancia os cavalos
    for (int i = 1; i <= 2; i++)
    {
        Cavalo *novoCavalo = new Cavalo(estilo);
        this->cavalos.push_back(novoCavalo);
    }

    // instancia rei e rainha
    this->rainha = new Rainha(estilo);
    this->rei = new Rei(estilo);*/
}

PecasPack::~PecasPack()
{
}

vector<Peca *> PecasPack::getPecasDisponiveis()
{
  vector<Peca *> pecasDisponiveis;

  for (int indice = 0; indice < this->peoes.size(); indice++)
  {
    Peca *peaoAtual = this->peoes[indice];
    if (peaoAtual && peaoAtual->getPosicaoAtual() != nullptr)
    {
      pecasDisponiveis.push_back(peaoAtual);
    }
  }

  return pecasDisponiveis;
}

string PecasPack::getEstilo()
{
  if (this)
  {
    return this->estilo;
  }
  return "";
}

void PecasPack::setPosicaoIncialPeoes(vector<Posicao *> *linhaInicialPeoes)
{
  vector<Peca *> *peoes = &(this->peoes);
  for (int indice = 0; indice < 8; indice++)
  {
    Posicao *posicaoAtual = (*linhaInicialPeoes)[indice];
    Peca *pecaAtual = (*peoes)[indice];
    //setta peça na posicao
    posicaoAtual->setPeca(pecaAtual);

    //setta posicao na peça
    pecaAtual->setPosicao(posicaoAtual);
  }
}

Posicao *PecasPack::getPosicaoRei()
{
  if (this)
  {
    return this->rei->getPosicaoAtual();
  }
  return nullptr;
}

bool PecasPack::verificaXequeAdversario(Posicao *posicaoReiAdversario)
{
  if (this)
  {
    vector<Posicao *> jogadasDisponiveisTodasPecas;
    vector<vector<Posicao *>> *matrizPosicoesTabuleiro;

    // posicao todos os peoes
    for (int indice = 0; indice <= this->peoes.size(); indice++)
    {
      Peca *peaoAtual = this->peoes[indice];
      vector<Posicao *> jogadasDisponiveisPeao;

      jogadasDisponiveisPeao = peaoAtual->getPosicoesValidas(matrizPosicoesTabuleiro);

      // caso o peao tenha jogadas disponiveis, insera as na lista de jogadas disponiveis do pacote de pecas
      if (!jogadasDisponiveisPeao.empty())
      {
        jogadasDisponiveisTodasPecas.insert(
            jogadasDisponiveisTodasPecas.end(),
            jogadasDisponiveisPeao.begin(),
            jogadasDisponiveisPeao.end());
      }
    }

    // checa se a posicao do rei adversario está inserida nas jogadas disponiveis do jogador
    for (int indice = 0; indice < jogadasDisponiveisTodasPecas.size(); indice++)
    {
      Posicao *jogadaAtual = jogadasDisponiveisTodasPecas[indice];
      if (jogadaAtual == posicaoReiAdversario)
      {
        return true;
      }
    }
  }
  return false;
}
