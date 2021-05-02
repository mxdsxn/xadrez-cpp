#include "PecasPack.h"

/**
 * @param pecaRemovida Peça para ser removida.
 * @param listaPecas Lista de peças.
 * @return Retorna 'true' quando a Peça for deletada da lista.
 */
bool deletaPeca(Peca *pecaRemovida, vector<Peca *> *listaPecas)
{
  for (int index = 0; index < listaPecas->size(); index++)
  {
    Peca *pecaAtual = (*listaPecas)[index];

    if (pecaRemovida == pecaAtual)
    {
      listaPecas->erase(listaPecas->begin() + index);
      return true;
    }
  }

  return false;
}

PecasPack::PecasPack(string estilo, bool sentidoJogador1)
{
  this->estilo = estilo;

  // instancia os peoes
  for (int i = 1; i <= 8; i++)
  {
    Peao *novoPeao = new Peao(estilo, sentidoJogador1);
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

/*
bool PecasPack::deletaRei()
{
    if (this)
    {
        this->rei->posicao->pecaAtual = nullptr;
        delete this->rei;
        this->rei = nullptr;
        return true;
    }
    return false;
}

bool PecasPack::deletaRainha()
{
    if (this)
    {
        this->rainha->posicao->pecaAtual = nullptr;
        delete this->rainha;
        this->rainha = nullptr;
        return true;
    }
    return false;
}

bool PecasPack::deletaTorre(Peca *torreRemovida)
{
    if (this)
    {
        for (int index = 0; index < this->torres.size(); index++)
        {
            Peca *torreAtual = this->torres[index];

            if (torreRemovida == torreAtual)
            {
                torreAtual->posicao->pecaAtual = nullptr;
                this->torres.erase(this->torres.begin() + index);
                return true;
            }
        }
    }
    return false;
}

bool PecasPack::deletaCavalo(Peca *cavaloRemovida)
{
    if (this)
    {
        for (int index = 0; index < this->cavalos.size(); index++)
        {
            Peca *cavaloAtual = this->cavalos[index];

            if (cavaloRemovida == cavaloAtual)
            {
                cavaloAtual->posicao->pecaAtual = nullptr;
                this->cavalos.erase(this->cavalos.begin() + index);
                return true;
            }
        }
    }
    return false;
}

bool PecasPack::deletaBispo(Peca *bispoRemovida)
{
    if (this)
    {
        for (int index = 0; index < this->bispos.size(); index++)
        {
            Peca *bispoAtual = this->bispos[index];

            if (bispoRemovida == bispoAtual)
            {
                bispoAtual->posicao->pecaAtual = nullptr;
                this->bispos.erase(this->bispos.begin() + index);
                return true;
            }
        }
    }
    return false;
}
*/

/**
 * @param peaoRemovida Peao para ser removida.
 * @return Retorna 'true' quando o Peao for deletado da lista.
 */
bool PecasPack::deletaPeao(Peca *peaoRemovida)
{
  if (this)
  {
    vector<Peca *> *listaPeoes = (vector<Peca *> *)&this->peoes;
    return deletaPeca(peaoRemovida, listaPeoes);
  }
  return false;
}

/**
 * @param linhaInicialPeoes Linha inicial dos Peoes.
 */
void PecasPack::setPosicaoIncialPeoes(vector<Posicao *> *linhaInicialPeoes)
{
  vector<Peao *> *peoes = &(this->peoes);
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
