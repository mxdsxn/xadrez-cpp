#include "sqlite3.h"

class SqlConnection
{
protected:
  sqlite3 *database;

public:
  SqlConnection();
  ~SqlConnection();
};
