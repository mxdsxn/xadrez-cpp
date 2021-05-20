#include <string>
#include <iostream>
#include "./JogadorSql.h"
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

JogadorSql::JogadorSql() : SqlConnection()
{
  char *zErrMsg = 0;
  int rc;

  string createTableQuery = "create table jogador_table(id integer primary key autoincrement,\
                                                        emXeque integer not null,\
                                                        nome varchar(10) not null,\
                                                        partida_id integer not null,\
                                                        FOREIGN KEY (partida_id) REFERENCES partida_table(id))";

  rc = sqlite3_exec(this->database, createTableQuery.c_str(), callback, 0, &zErrMsg);

  if (rc != SQLITE_OK)
  {
    cout << "SQL error: " << sqlite3_errmsg(this->database) << "\n";
    sqlite3_free(zErrMsg);
  }
}

JogadorSql::~JogadorSql() {}

int JogadorSql::salvar(int idPartida, bool emXeque, string nome)
{
  char *zErrMsg = 0;
  int rc;

  string addQuery = "insert into jogador_table (emXeque, nome, partida_id)\
      values(" + to_string(emXeque ? 1 : 0) +
                    ", '" + nome + "'" +
                    ", " + to_string(idPartida) + ") ";

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
    int idNovoJogador = sqlite3_last_insert_rowid(this->database);
    return idNovoJogador;
  }

  return 0;
}
