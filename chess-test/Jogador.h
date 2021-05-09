#pragma once
#include <string>
#include "./PecasPack.h"

using namespace std;

class Jogador
{
private:
  string nome;
  PecasPack *pecas;
  bool emXeque;

public:
  Jogador(string nome, PecasPack *pecas);

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
     * @return Retorna TRUE quando o jogador atual colocou o Rei do jogadorAdversario em Xeque.
     */
  bool verificaReiAdversarioXeque(Posicao *posicaoReiAdversario);
};
