/**
 * Limpa o console
 */
void clear();

/**
 * Limpa o buffer
 */
void cleanBuffer();

struct CoordenadasStr
{
  string x, y;
};

/**
 * Coverte coordenadas de uma posição para ser mostrada no console
 * @param posicao Posição que precisa ser formatada as coordenadas
 * @return Retorna uma lista de tamanho 2. Primeiro item X, segundo item, Y.
 * | Lista vazia caso as coordenadas não atendam a regra.
 */
CoordenadasStr posicaoToCoordStr(Posicao *posicao);

/**
 * Formata coordenadas para o formato [A, 1]
 * @param coordenadas Coordenadas para serem formatadas.
 * @return Retorna uma string no formato [A, 1].
 */
string formataCoordenadas(CoordenadasStr coordenadas);
