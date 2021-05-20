#pragma once

#include "../pecas/pecaBase/Peca.h"
#include "../posicao/Posicao.h"
#include "../tabuleiro/Tabuleiro.h"
#include "./pacotePecasDAO/PacotePecasDAO.h"

class Peca;
class Tabuleiro;
class PacotePecasDAO;

class PecasPack
{
private:
  string estilo;
  vector<Peca *> peoes;
  vector<Peca *> torres;
  vector<Peca *> bispos;
  vector<Peca *> cavalos;
  Peca *rei;
  Peca *rainha;
  Tabuleiro *tabuleiro;
  bool emXeque;
  PacotePecasDAO *pacotePecasDAO;

public:
  PecasPack(string estilo, bool sentidoPraFrente, Tabuleiro *tabuleiro);
  ~PecasPack();

  /**
     * @return Retorna `branco` ou `preto`.
     */
  string getEstilo();

  /**
     * @return Retorna posição atual do rei.
     */
  Posicao *getPosicaoRei();

  /**
   * @param posicoesTabuleiro Matriz de posicoes do tabuleiro.
   * @return Lista de pecas disponiveis para executar jogada
   */
  vector<Peca *> getPecasDisponiveisJogadas(vector<vector<Posicao *>> *posicoesTabuleiro);

  /**
     * Filtra jogadas possiveis para uma peça adversaria, para que a jogada nao coloque o rei adversario em xeque
     * @param pecaSelecionadaAdversario Peca em que o jogador ADVERSARIO selecionou para movimentar
     * @return Lista de jogadas para a pecaSelecionadaAdversario, jogadas essas que nao coloquem o ReiAdversario em Xeque
     */
  vector<Posicao *> getJogadasDisponiveisFiltrandoRiscoXeque(Peca *pecaSelecionadaAdversario);

  /**
     * @param emXeque TRUE quando o rei estiver em xeque.
     */
  void setXeque(bool emXeque);

  /**
     * @return Booleano com estado atual de xeque do pacote
     */
  bool getXeque();

  /**
     * Setta posicoes inciais para os peoes.
     * @param linhaInicialPeoes Linha inicial dos Peoes no tabuleiro .
     */
  void setPosicaoInicialPeoes(vector<Posicao *> *linhaInicialPeoes);

  /**
     * Setta posicoes inciais para as peças da realeza.
     * @param linhaInicialRealeza Linha inicial dos Peoes no tabuleiro .
     */
  void setPosicaoInicialRealeza(vector<Posicao *> *linhaInicialRealeza);

  /**
     * Verifica se o pacote adversario está com o rei em xeque
     * @param posicaoReiAdversario posição do rei adversario
     * @return Retorna TRUE quando alguma das peças do pacote coloca o Rei adversario em Xeque.
     */
  bool verificaReiAdversarioXeque(Posicao *posicaoReiAdversario);

  /**
     * @return Lista com todas as peças do pacote
     */
  vector<Peca *> getTodasPecas();

  /**
   * Salva pacotePecas
   * @param idJogador Jogador associado ao pacotePecas
   * @return 0 caso tenha ocorrido erro ao salvar OU id do pacotePecas no banco
  */
  int salvar(int idJogador);
};
