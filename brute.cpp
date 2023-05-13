#include "project.h"
using namespace std;

int brute(string T, string P);

int brute(string T, string P)
{

  if (T.length() >= P.length())
  {
    for (int indexT = 0; indexT <= T.length() - P.length(); ++indexT)
    {
      int indexP = 0;

      while (indexP < P.length() and T[indexT + indexP] == P[indexP])
      {
        ++indexP;

        if (indexP == P.length())
          return indexT;
      }
    }
  }

  return -1;
}
