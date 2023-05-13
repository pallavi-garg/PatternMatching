#include "project.h"
using namespace std;

int rk(string T, string P);

int getHashCode(char character)
{
  return character;
}

int cyclicShiftBy(int number, int shiftBy)
{
  return (number << shiftBy & 1) | (number >> (32 - shiftBy));
}

int getHashCode(string &text, int startIndex, int length)
{
  int hashCode = 0;
  int index = startIndex;

  for (; index < startIndex + length - 1; ++index)
    hashCode ^= cyclicShiftBy(getHashCode(text[index]), length - index - 1);
  hashCode ^= getHashCode(text[index]);

  return hashCode;
}

int getShiftedHash(int previousHash, string &text, int newStartIndex, int patternLength)
{
  return cyclicShiftBy(previousHash, 1) ^ cyclicShiftBy(getHashCode(text[newStartIndex - 1]), patternLength) ^ getHashCode(text[newStartIndex + patternLength - 1]);
}

bool isTrueMatch(string &text, string &pattern, int textIndex)
{
  int patternLength = pattern.length();
  bool match = true;
  for (int index = 0; index < patternLength; ++index)
  {
    if (pattern[index] != text[textIndex + index])
    {
      match = false;
      break;
    }
  }
  return match;
}

int rk(string T, string P)
{
  int retIndex = -1;
  int patternLength = P.length();
  int indexToGo = T.length() - patternLength;

  if (patternLength > 0 and indexToGo >= 0)
  {
    int pHashCode = getHashCode(P, 0, patternLength);
    int hashCode;

    for (int index = 0; index <= indexToGo; ++index)
    {
      if (index == 0)
        hashCode = getHashCode(T, index, patternLength);
      else
        hashCode = getShiftedHash(hashCode, T, index, patternLength);

      if (pHashCode == hashCode and isTrueMatch(T, P, index))
      {
        retIndex = index;
        break;
      }
    }
  }

  return retIndex;
}
