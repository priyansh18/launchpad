#include <iostream>
using namespace std;
void naiveSearch(string str, string pat)
{
  for (int i = 0; i <= str.size() - pat.size(); i++)
  {
    int j;
    for (j = 0; j < pat.size(); j++)
    {
      if (str[i + j] != pat[j])
      {
        break;
      }
    }
    if (j == pat.size())
    {
      cout << "Pattern found at index " << i << endl;
    }
  }
}

int main()
{
  // time complexity: O(mn)
  string str, pattern;
  cin >> str >> pattern;
  naiveSearch(str, pattern);
  return 0;
}