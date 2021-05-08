#include <iostream>
#include <string>

#include "./utils.h"

void clear()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
  system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
  system("cls");
#endif
}

void cleanBuffer()
{
  std::string buffer;
  getline(std::cin, buffer);
}
