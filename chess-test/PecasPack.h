#pragma once

#include "./Peao.h"
#include "./Posicao.h"

class Peca;

class PecasPack
{
public:
    vector<Peao *> peoes;
    string estilo;

    PecasPack(string estilo);
    ~PecasPack();

    vector<Peca *> getPecasDisponiveis();

    /**
     * @return Retorna 'true' quando o Rei for deletado.
     */
    //bool deletaRei();

    /**
     * @return Retorna 'true' quando a Rainha for deletada.
     */
    //bool deletaRainha();

    /**
     * @param torreRemovida Torre para ser removida.
     * @return Retorna 'true' quando a Torre for deletada.
     */
    //bool deletaTorre(Peca *torreRemovida);

    /**
     * @param cavaloRemovida Cavalo para ser removida.
     * @return Retorna 'true' quando o Cavalo for deletada.
     */
    //bool deletaCavalo(Peca *cavaloRemovida);

    /**
     * @param bispoRemovida Bispo para ser removida.
     * @return Retorna 'true' quando o Bispo for deletada.
     */
    //bool deletaBispo(Peca *bispoRemovida);

    /**
     * @param peaoRemovida Peao para ser removida.
     * @return Retorna 'true' quando o Peao for deletada.
     */
    bool deletaPeao(Peca *peaoRemovida);

    /**
     * @param linhaInicialPeoes Linha inicial dos Peoes no tabuleiro .
     */
    void setPosicaoIncialPeoes(vector<Posicao *> *linhaInicialPeoes);
};
