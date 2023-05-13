#include "project.h"
#include <unordered_map>
using namespace std;

int bmh(string T, string P);

unordered_map<char, int> getLastOccurrence(string str);

int bmh(string T, string P)
{

  int tLength = T.length();
  int pLength = P.length();

  if (pLength <= tLength)
  {
    unordered_map<char, int> lastOccurence = getLastOccurrence(P);

    int indexT = pLength - 1;
    int indexP = indexT;

    while (indexT <= tLength - 1)
    {
      if (T[indexT] == P[indexP])
      {
        if (indexP == 0)
          return indexT;
        else
        {
          indexT--;
          indexP--;
        }
      }
      else
      {
        indexT = indexT + pLength - min(indexP, lastOccurence[T[indexT]] + 1);
        indexP = pLength - 1;
      }
    }
  }
  return -1;
}

unordered_map<char, int> getLastOccurrence(string str)
{
  unordered_map<char, int> lastOccurence;

  for (int index = 0; index < str.size(); ++index)
    lastOccurence[str[index]] = index;

  return lastOccurence;
}