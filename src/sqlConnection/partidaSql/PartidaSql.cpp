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

int PartidaSql::salvar(bool turnoPrimeiroJogador, int codigoTipo, int sql_idPartida)
{
  char *zErrMsg = 0;
  int rc;

  string addQuery = "insert into partida_table (turnoPrimeiroJogador, codigoTipo)\
      values(" + to_string(turnoPrimeiroJogador ? 1 : 0) +
                    ", " + to_string(codigoTipo) + ") ";
  string updateQuery = ("update partida_table set turnoPrimeiroJogador = " + to_string(turnoPrimeiroJogador ? 1 : 0) +
                        ", codigoTipo = " + to_string(codigoTipo) +
                        " where partida_table.id = " + to_string(sql_idPartida));

  string query = sql_idPartida == -1 ? addQuery : updateQuery;

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
    int idNovaPartida = sqlite3_last_insert_rowid(this->database);
    return idNovaPartida;
  }

  return 0;
}

int callbackSqlPartida(void *NotUsed, int argc, char **argv, char **azColName)
{
  int i;
  FabricaPartida *fabricaPartida = new FabricaPartida();

  vector<Partida *> *result = (vector<Partida *> *)NotUsed;

  int idPartida = argv[0] ? atoi(argv[0]) : -1;
  bool turnoPrimeiroJogador = argv[1] ? atoi(argv[1]) == 1 : false;
  int codigoTipo = argv[2] ? atoi(argv[2]) : -1;

  Partida *novaPartida = fabricaPartida->recuperaPartida(idPartida, turnoPrimeiroJogador, codigoTipo);

  result->push_back(novaPartida);
  return 0;
}

vector<Partida *> PartidaSql::recuperar(int idPartida)
{
  vector<Partida *> result;

  char *zErrMsg = 0;
  int rc;

  string selectQuery = ("select * from  partida_table" + ((idPartida != -1) ? " where partida_table.id = " + to_string(idPartida) : ""));

  rc = sqlite3_exec(this->database, selectQuery.c_str(), callbackSqlPartida, &result, &zErrMsg);

  if (rc != SQLITE_OK)
  {
    //cout << "SQL error: " << sqlite3_errmsg(this->database) << "\n";
    sqlite3_free(zErrMsg);
    return result;
  }

  return result;
}

void PartidaSql::deletar(int idPartida)
{
  char *zErrMsg = 0;
  int rc;

  string deleteQuery = "delete from partida_table where partida_table.id = " + to_string(idPartida);

  rc = sqlite3_exec(this->database, deleteQuery.c_str(), callbackSql, 0, &zErrMsg);

  if (rc != SQLITE_OK)
  {
    cout << zErrMsg << endl;
    cout << *zErrMsg << endl;
    cleanBuffer();
    sqlite3_free(zErrMsg);
  }
}
