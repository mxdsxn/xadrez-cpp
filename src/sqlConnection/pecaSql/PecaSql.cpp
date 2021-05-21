#include <string>
#include <iostream>
#include "./PecaSql.h"
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

  rc = sqlite3_exec(this->database, createTableQuery.c_str(), callback, 0, &zErrMsg);

  if (rc != SQLITE_OK)
  {
    cout << "SQL error: " << sqlite3_errmsg(this->database) << "\n";
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
    int codigoTipo)
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

  cout << addQuery << endl;
  cleanBuffer();

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
    int idNovaPeca = sqlite3_last_insert_rowid(this->database);
    return idNovaPeca;
  }

  return 0;
}
