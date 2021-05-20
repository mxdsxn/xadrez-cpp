#pragma once

#include "sqlite3.h"

/**
 * Abre e fecha conexão com o banco de dados e funciona como base para outras classes que desejam usar o mesmo banco
*/
class SqlConnection
{
protected:
  sqlite3 *database;

public:
  SqlConnection();
  ~SqlConnection();
};
