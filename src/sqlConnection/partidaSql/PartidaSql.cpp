#include <string>
#include <iostream>
#include "./PartidaSql.h"
#include "../../utils/utils.h"

using namespace std;

PartidaSql::PartidaSql() : SqlConnection()
{
  char *zErrMsg = 0;
  int rc;

  string createTableQuery = "create table partida_table(id integer primary key autoincrement, turnoPrimeiroJogador integer not null, codigoTipo integer not null)";

  rc = sqlite3_exec(this->database, createTableQuery.c_str(), callbackSql, 0, &zErrMsg);

  if (rc != SQLITE_OK)
  {
    //cout << "SQL error: " << sqlite3_errmsg(this->database) << "\n";
    sqlite3_free(zErrMsg);
  }
}

PartidaSql::~PartidaSql() {}

int PartidaSql::salvar(bool turnoPrimeiroJogador, int codigoTipo)
{
  char *zErrMsg = 0;
  int rc;

  string addQuery = "insert into partida_table (turnoPrimeiroJogador, codigoTipo)\
      values(" + to_string(turnoPrimeiroJogador ? 1 : 0) +
                    ", " + to_string(codigoTipo) + ") ";

  rc = sqlite3_exec(this->database, addQuery.c_str(), callbackSql, 0, &zErrMsg);

  if (rc != SQLITE_OK)
  {
    cout << zErrMsg << endl;
    cout << *zErrMsg << endl;
    cleanBuffer();
    sqlite3_free(zErrMsg);
  }
  else
  {
    int idNovaPartida = sqlite3_last_insert_rowid(this->database);
    return idNovaPartida;
  }

  return 0;
}