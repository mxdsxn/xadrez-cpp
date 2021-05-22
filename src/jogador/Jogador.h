#pragma once
#include <string>
#include "../pacotePecas/PecasPack.h"
#include "./jogadorDAO/JogadorDAO.h"

using namespace std;

class JogadorDAO;
class Jogador
{
private:
  string nome;
  PecasPack *pecas;
  bool emXeque;
  JogadorDAO *jogadorDAO;
  int sql_idJogador;

public:
  Jogador(string nome, PecasPack *pecas);
  Jogador(int idJogador, bool emXeque, string nome);
  ~Jogador();

  /**
     * @return Retorna nome do jogador.
     */
  string getNome();

  /**
     * @return Retorna pacote de peças do jogador.
     */
  PecasPack *getPacotePecas();

  /**
     * @return Retorna posição atual do rei do pacote de pecas do jogador.
     */
  Posicao *getPosicaoRei();

  /**
     * @param emXeque TRUE quando o jogador estiver em xeque.
     */
  void setXeque(bool emXeque);

  /**
     * @return Booleano com o estado atual de xeque do jogador.
     */
  bool getXeque();

  /**
     * @return Retorna TRUE quando o jogador atual colocou o Rei do jogadorAdversario em Xeque.
     */
  bool verificaReiAdversarioXeque(Posicao *posicaoReiAdversario);

  /**
     * Essa funçao verifica se apos o adversario ser colocado em xeque, alguma peça do tabuleiro consegue ser movimentada para mudar essa situacao
     * @return Retorna TRUE quando o jogador atual finaliza a partida.
     */
  bool verificaXequeMate(Jogador *adversario, vector<vector<Posicao *>> *posicoesTabuleiro);

  /**
   * Salva jogador
   * @param idPartida Partida associada ao jogador
   * @return 0 caso tenha ocorrido erro ao salvar OU id do jogador no banco
  */
  int salvar(int idPartida);
};
