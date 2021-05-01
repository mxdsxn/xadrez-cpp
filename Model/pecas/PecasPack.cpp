#include "PecasPack.h"

PecasPack::PecasPack(string estilo, Tabuleiro *tabuleiro)
{
    // instancia os peoes
    for (int i = 1; i <= 8; i++)
    {
        Peao *novoPeao = new Peao(estilo, tabuleiro, nullptr);
        this->peoes.push_back(novoPeao);
    }

    // instancia os torres
    for (int i = 1; i <= 2; i++)
    {
        Torre *novaTorre = new Torre(estilo, tabuleiro, nullptr);
        this->torres.push_back(novaTorre);
    }

    // instancia os bispos
    for (int i = 1; i <= 2; i++)
    {
        Bispo *novoBispo = new Bispo(estilo, tabuleiro, nullptr);
        this->bispos.push_back(novoBispo);
    }

    // instancia os cavalos
    for (int i = 1; i <= 2; i++)
    {
        Cavalo *novoCavalo = new Cavalo(estilo, tabuleiro, nullptr);
        this->cavalos.push_back(novoCavalo);
    }

    // instancia rei e rainha
    this->rainha = new Rainha(estilo, tabuleiro, nullptr);
    this->rei = new Rei(estilo, tabuleiro, nullptr);
}

PecasPack::~PecasPack()
{
}

vector<Peca *> PecasPack::getPecasDisponiveis()
{
    vector<Peca *> pecasDisponiveis;

    return pecasDisponiveis;
}

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
            pecaAtual->posicao->pecaAtual = nullptr;
            listaPecas->erase(listaPecas->begin() + index);
            return true;
        }
    }

    return false;
}