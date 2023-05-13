#include "project.h"
#include <vector>
using namespace std;

int bitap(string T, string P);

int bitap(string T, string P)
{
  int retIndex = -1;

  int patternLength = P.length();
  int textLength = T.length();

  if (patternLength > 0 and textLength > 0)
  {
    int alphabetSize = 256;

    vector<long> patternMask(alphabetSize, ~0);
    long X = ~1;

    for (int i = 0; i < patternLength; i++)
      patternMask[P[i]] &= ~(1L << i);

    for (int i = 0; i < textLength; i++)
    {
      X |= patternMask[T[i]];
      X <<= 1;
      if ((X & (1L << patternLength)) == 0)
      {
        retIndex = i - patternLength + 1;
        break;
      }
    }
  }
  return retIndex;
}
