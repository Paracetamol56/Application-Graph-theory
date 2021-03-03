
#include "test.hpp"

/*!
 * \brief
 * La couleur par défaut du texte.
 */
const WORD g_wDefaultColor = GetDefaultColor();

const char* colored(const char* text, WORD color)
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
  return text;
}

WORD GetDefaultColor()
{
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.wAttributes;
}
