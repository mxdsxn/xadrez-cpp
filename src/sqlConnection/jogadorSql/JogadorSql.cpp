#include <string>
#include <iostream>
#include "./JogadorSql.h"
#include "../../utils/utils.h"

using namespace std;

JogadorSql::JogadorSql() : SqlConnection()
{
  char *zErrMsg = 0;
  int rc;

  string createTableQuery = "create table jogador_table(id integer primary key autoincrement,\
                                                        emXeque integer not null,\
                                                        nome varchar(10) not null,\
                                                        partida_id integer not null,\
                                                        FOREIGN KEY (partida_id) REFERENCES partida_table(id))";

  rc = sqlite3_exec(this->database, createTableQuery.c_str(), callbackSql, 0, &zErrMsg);

  if (rc != SQLITE_OK)
  {
    //cout << "SQL error: " << sqlite3_errmsg(this->database) << "\n";
    sqlite3_free(zErrMsg);
  }
}

JogadorSql::~JogadorSql() {}

int JogadorSql::salvar(int idPartida, bool emXeque, string nome, int sql_idJogador)
{
  char *zErrMsg = 0;
  int rc;

  string addQuery = "insert into jogador_table (emXeque, nome, partida_id)\
      values(" + to_string(emXeque ? 1 : 0) +
                    ", '" + nome + "'" +
                    ", " + to_string(idPartida) + ") ";

  string updateQuery = ("update jogador_table set emXeque = " + to_string(emXeque ? 1 : 0) +
                        ", nome = '" + nome + "'" +
                        " where jogador_table.id = " + to_string(sql_idJogador));

  string query = sql_idJogador == -1 ? addQuery : updateQuery;

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
    int idNovoJogador = sqlite3_last_insert_rowid(this->database);
    return idNovoJogador;
  }

  return 0;
}

int callbackSqlJogador(void *NotUsed, int argc, char **argv, char **azColName)
{
  int i;
  vector<Jogador *> *result = (vector<Jogador *> *)NotUsed;

  int idJogador = argv[0] ? atoi(argv[0]) : -1;
  bool emXeque = argv[1] ? atoi(argv[1]) == 1 : false;
  string nome = argv[2] ? argv[2] : "[ERROR] - JOGADOR_NAME";

  Jogador *novoJogador = new Jogador(idJogador, emXeque, nome);

  result->push_back(novoJogador);

  return 0;
}

vector<Jogador *> JogadorSql::recuperar(int idPartida)
{
  vector<Jogador *> result;

  char *zErrMsg = 0;
  int rc;

  string selectQuery = ("select * from  jogador_table" + ((idPartida != -1) ? " where jogador_table.partida_id = " + to_string(idPartida) : ""));

  rc = sqlite3_exec(this->database, selectQuery.c_str(), callbackSqlJogador, &result, &zErrMsg);

  if (rc != SQLITE_OK)
  {
    //cout << "SQL error: " << sqlite3_errmsg(this->database) << "\n";
    sqlite3_free(zErrMsg);
    return result;
  }

  return result;
}

void JogadorSql::deletar(int idJogador)
{
  char *zErrMsg = 0;
  int rc;

  string deleteQuery = "delete from jogador_table where jogador_table.id = " + to_string(idJogador);

  rc = sqlite3_exec(this->database, deleteQuery.c_str(), callbackSql, 0, &zErrMsg);

  if (rc != SQLITE_OK)
  {
    cout << zErrMsg << endl;
    cout << *zErrMsg << endl;
    cleanBuffer();
    sqlite3_free(zErrMsg);
  }
}
