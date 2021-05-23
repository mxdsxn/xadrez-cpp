#include <string>
#include <iostream>
#include "./PacotePecasSql.h"
#include "../../utils/utils.h"

using namespace std;

PacotePecasSql::PacotePecasSql() : SqlConnection()
{
  char *zErrMsg = 0;
  int rc;

  string createTableQuery = "create table pacote_pecas_table(id integer primary key autoincrement,\
                                                             emXeque integer not null,\
                                                             estilo varchar(10) not null,\
                                                             jogador_id integer not null,\
                                                             FOREIGN KEY (jogador_id) REFERENCES jogador_table(id))";

  rc = sqlite3_exec(this->database, createTableQuery.c_str(), callbackSql, 0, &zErrMsg);

  if (rc != SQLITE_OK)
  {
    //cout << "SQL error: " << sqlite3_errmsg(this->database) << "\n";
    sqlite3_free(zErrMsg);
  }
}

PacotePecasSql::~PacotePecasSql() {}

int PacotePecasSql::salvar(int idJogador, bool emXeque, string estilo, int sql_idPacotePeca)
{
  char *zErrMsg = 0;
  int rc;

  string addQuery = "insert into pacote_pecas_table (emXeque, estilo, jogador_id)\
      values(" + to_string(emXeque ? 1 : 0) +
                    ", '" + estilo + "'" +
                    ", " + to_string(idJogador) + ") ";

  string updateQuery = ("update pacote_pecas_table set emXeque = " + to_string(emXeque ? 1 : 0) +
                        ", estilo = '" + estilo + "'" +
                        " where pacote_pecas_table.id = " + to_string(sql_idPacotePeca));

  string query = sql_idPacotePeca == -1 ? addQuery : updateQuery;

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
    int idNovoPacotePecas = sqlite3_last_insert_rowid(this->database);
    return idNovoPacotePecas;
  }

  return 0;
}

int callbackSqlPacotePecas(void *NotUsed, int argc, char **argv, char **azColName)
{
  int i;
  vector<PecasPack *> *result = (vector<PecasPack *> *)NotUsed;

  int idPecasPack = argv[0] ? atoi(argv[0]) : -1;
  bool emXeque = argv[1] ? atoi(argv[1]) == 1 : false;
  string estilo = argv[2] ? argv[2] : "[ERROR] - JOGADOR_NAME";

  PecasPack *novoPacotePecas = new PecasPack(idPecasPack, emXeque, estilo);

  result->push_back(novoPacotePecas);

  return 0;
}

vector<PecasPack *> PacotePecasSql::recuperar(int idJogador)
{
  vector<PecasPack *> result;

  char *zErrMsg = 0;
  int rc;

  string selectQuery = ("select * from  pacote_pecas_table" + ((idJogador != -1) ? " where pacote_pecas_table.jogador_id = " + to_string(idJogador) : ""));

  rc = sqlite3_exec(this->database, selectQuery.c_str(), callbackSqlPacotePecas, &result, &zErrMsg);

  if (rc != SQLITE_OK)
  {
    //cout << "SQL error: " << sqlite3_errmsg(this->database) << "\n";
    sqlite3_free(zErrMsg);
    return result;
  }

  return result;
}
