#include <iostream>
#include <algorithm>
#include <cmath>
#define prime 119
#define ll long long
using namespace std;
ll createHashValue(string str, int n)
{
  int result = 0;
  for (int i = 0; i < n; i++)
  {
    result += (ll)(str[i] * (ll)pow(prime, i));
  }
  return result;
}
ll reCalculateHashValue(string str, int oldIndex, int newIndex, ll oldHash, int patlength)
{
  ll newHash = oldHash - str[oldIndex];
  newHash /= prime;
  newHash += (ll)(str[newIndex] * (ll)(pow(prime, patlength - 1)));
  return newHash;
}
bool checkEqual(string str1, string str2, int start1, int end1, int start2, int end2)
{
  if (end1 - start1 != end2 - start2)
  {
    return false;
  }
  while (start1 <= end1 && start2 <= end2)
  {
    if (str1[start1] != str2[start2])
    {
      return false;
    }
    start1++;
    start2++;
  }
  return true;
}
int main()
{
  string string, pattern;
  cin >> string >> pattern;
  ll patHash = createHashValue(pattern, pattern.length());
  ll strHash = createHashValue(string, pattern.length());
  for (int i = 0; i <= string.length() - pattern.length(); i++)
  {
    if (patHash == strHash and checkEqual(string, pattern, i, i + pattern.length() - 1, 0, pattern.length() - 1))
    {
      cout << i << endl;
      return 0;
    }
    if (i < string.length() - pattern.length())
    {
      strHash =
          reCalculateHashValue(string, i, i + pattern.length(), strHash, pattern.length());
    }
  }

  return 0;
}