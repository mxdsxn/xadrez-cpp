#include "./SqlConnection.h"

SqlConnection::SqlConnection()
{
  int rc;
  rc = sqlite3_open("mxadrez.db", &this->database);
}

SqlConnection::~SqlConnection()
{
  sqlite3_close(this->database);
}
