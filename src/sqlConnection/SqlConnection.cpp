#include <iostream>
#include "./SqlConnection.h"
#include "../utils/utils.h"

using namespace std;

SqlConnection::SqlConnection()
{
  int rc;
  rc = sqlite3_open("mxadrez.db", &this->database);

  if (rc)
  {
    cout << "Can't open database: " << sqlite3_errmsg(this->database) << endl;
    cleanBuffer();
  }
  else
  {
    //cout << "Open database successfully\n\n";
    //cleanBuffer();
  }
}

SqlConnection::~SqlConnection()
{
  sqlite3_close(this->database);
}
