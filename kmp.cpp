#include "project.h"
#include <vector>
using namespace std;

int kmp(string T, string P);

vector<int> getFailureFunction(string P);

int kmp(string T, string P)
{

  int tLength = T.length();
  int pLength = P.length();

  if (pLength <= tLength)
  {
    vector<int> failureFunction = getFailureFunction(P);
    int indexT = 0, indexP = 0;

    while (indexT < tLength)
    {
      if (T[indexT] == P[indexP])
      {
        if (indexP == pLength - 1)
          return indexT - indexP;
        else
        {
          ++indexT;
          ++indexP;
        }
      }
      else
      {
        if (indexP > 0)
          indexP = failureFunction[indexP - 1];
        else
          ++indexT;
      }
    }
  }

  return -1;
}

vector<int> getFailureFunction(string P)
{
  vector<int> failureFunction(P.length(), 0);
  int i = 1;
  int j = 0;
  while (i < P.length())
  {
    if (P[i] == P[j])
      failureFunction[i++] = ++j;
    else if (j > 0)
      j = failureFunction[j - 1];
    else
      failureFunction[i++] = 0;
  }
  return failureFunction;
}
