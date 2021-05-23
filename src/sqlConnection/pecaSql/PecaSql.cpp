#include <string>
#include <iostream>
#include "./PecaSql.h"
#include "../../utils/utils.h"

using namespace std;

PecaSql::PecaSql() : SqlConnection()
{
  char *zErrMsg = 0;
  int rc;

  string createTableQuery = "create table peca_table(id integer primary key autoincrement,\
                                                     emXeque integer not null,\
                                                     sentidoPraFrente integer not null,\
                                                     primeiraJogada integer not null,\
                                                     codigoTipo integer not null,\
                                                     coordenada_x integer not null,\
                                                     coordenada_y integer not null,\
                                                     pacote_pecas_id integer not null,\
                                                     FOREIGN KEY (pacote_pecas_id) REFERENCES pacote_pecas_table(id)\
                                                     )";

  rc = sqlite3_exec(this->database, createTableQuery.c_str(), callbackSql, 0, &zErrMsg);

  if (rc != SQLITE_OK)
  {
    //cout << "SQL error: " << sqlite3_errmsg(this->database) << "\n";
    sqlite3_free(zErrMsg);
  }
}

PecaSql::~PecaSql() {}

int PecaSql::salvar(
    int idPacotePecas,
    bool emXeque,
    bool sentidoPraFrente,
    bool primeiraJogada,
    int coordenada_y,
    int coordenada_x,
    int codigoTipo,
    int sql_idPeca)
{
  char *zErrMsg = 0;
  int rc;

  string addQuery = "insert into peca_table (emXeque,\
                                             sentidoPraFrente,\
                                             primeiraJogada,\
                                             codigoTipo,\
                                             coordenada_y,\
                                             coordenada_x,\
                                             pacote_pecas_id\
                                             )\
                                             values\
                                             (" +
                    to_string(emXeque ? 1 : 0) + ", " +
                    to_string(sentidoPraFrente ? 1 : 0) + ", " +
                    to_string(primeiraJogada ? 1 : 0) + ", " +
                    to_string(codigoTipo) + ", " +
                    to_string(coordenada_y) + ", " +
                    to_string(coordenada_x) + ", " +
                    to_string(idPacotePecas) +
                    ") ";

  string updateQuery = ("update peca_table set emXeque = " + to_string(emXeque ? 1 : 0) +
                        ", sentidoPraFrente = " + to_string(sentidoPraFrente ? 1 : 0) +
                        ", primeiraJogada = " + to_string(primeiraJogada ? 1 : 0) +
                        ", codigoTipo = " + to_string(codigoTipo) +
                        ", coordenada_y = " + to_string(coordenada_y) +
                        ", coordenada_x = " + to_string(coordenada_x) +
                        " where peca_table.id = " + to_string(sql_idPeca));

  string query = sql_idPeca == -1 ? addQuery : updateQuery;

  rc = sqlite3_exec(this->database, query.c_str(), callbackSql, 0, &zErrMsg);

  if (rc != SQLITE_OK)
  {
    cout << zErrMsg << endl;
    cout << *zErrMsg << endl;
    cleanBuffer();
    sqlite3_free(zErrMsg);
  }
  else
  {
    int idNovaPeca = sqlite3_last_insert_rowid(this->database);
    return idNovaPeca;
  }

  return 0;
}

int callbackSqlPeca(void *NotUsed, int argc, char **argv, char **azColName)
{
  int i;
  FabricaPeca *fabricaPeca = new FabricaPeca();

  vector<Peca *> *result = (vector<Peca *> *)NotUsed;

  int idPeca = argv[0] ? atoi(argv[0]) : -1;
  bool emXeque = argv[1] ? atoi(argv[1]) == 1 : false;
  bool sentidoPraFrente = argv[2] ? atoi(argv[2]) == 1 : false;
  bool primeiraJogada = argv[3] ? atoi(argv[3]) == 1 : false;
  int codigoTipo = argv[4] ? atoi(argv[4]) : -1;
  int coordenada_x = argv[5] ? atoi(argv[5]) : -1;
  int coordenada_y = argv[6] ? atoi(argv[6]) : -1;

  Peca *novaPeca = fabricaPeca->recuperaPeca(idPeca,
                                             emXeque,
                                             sentidoPraFrente,
                                             primeiraJogada,
                                             codigoTipo,
                                             coordenada_x,
                                             coordenada_y);

  result->push_back(novaPeca);

  return 0;
}

vector<Peca *> PecaSql::recuperar(int idPacotePeca)
{
  vector<Peca *> result;

  char *zErrMsg = 0;
  int rc;

  string selectQuery = ("select * from  peca_table" + ((idPacotePeca != -1) ? " where peca_table.pacote_pecas_id = " + to_string(idPacotePeca) : ""));

  rc = sqlite3_exec(this->database, selectQuery.c_str(), callbackSqlPeca, &result, &zErrMsg);

  if (rc != SQLITE_OK)
  {
    //cout << "SQL error: " << sqlite3_errmsg(this->database) << "\n";
    sqlite3_free(zErrMsg);
    return result;
  }

  return result;
}

void PecaSql::deletar(int idPeca)
{
  char *zErrMsg = 0;
  int rc;

  string deleteQuery = "delete from peca_table where peca_table.id = " + to_string(idPeca);

  rc = sqlite3_exec(this->database, deleteQuery.c_str(), callbackSql, 0, &zErrMsg);

  if (rc != SQLITE_OK)
  {
    cout << zErrMsg << endl;
    cout << *zErrMsg << endl;
    cleanBuffer();
    sqlite3_free(zErrMsg);
  }
}
