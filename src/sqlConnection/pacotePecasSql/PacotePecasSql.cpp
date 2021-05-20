#include <string>
#include <iostream>
#include "./PacotePecasSql.h"
#include "../../utils/utils.h"

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
  int i;
  for (i = 0; i < argc; i++)
  {
    cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << "\n";
  }
  return 0;
}

PacotePecasSql::PacotePecasSql() : SqlConnection()
{
  char *zErrMsg = 0;
  int rc;

  string createTableQuery = "create table pacote_pecas_table(id integer primary key autoincrement,\
                                                             emXeque integer not null,\
                                                             estilo varchar(10) not null,\
                                                             jogador_id integer not null,\
                                                             FOREIGN KEY (jogador_id) REFERENCES jogador_table(id))";

  rc = sqlite3_exec(this->database, createTableQuery.c_str(), callback, 0, &zErrMsg);

  if (rc != SQLITE_OK)
  {
    cout << "SQL error: " << sqlite3_errmsg(this->database) << "\n";
    sqlite3_free(zErrMsg);
  }
}

PacotePecasSql::~PacotePecasSql() {}

int PacotePecasSql::salvar(int idJogador, bool emXeque, string estilo)
{
  char *zErrMsg = 0;
  int rc;

  string addQuery = "insert into pacote_pecas_table (emXeque, estilo, jogador_id)\
      values(" + to_string(emXeque ? 1 : 0) +
                    ", '" + estilo + "'" +
                    ", " + to_string(idJogador) + ") ";

  rc = sqlite3_exec(this->database, addQuery.c_str(), callback, 0, &zErrMsg);

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
