#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool balanceParanthesis(string str)
{
  stack<char> s;
  for (int i = 0; i < str.size(); i++)
  {
    char currentChar = str[i];
    if (currentChar == '(')
    {
      s.push(currentChar);
    }
    else if (currentChar == ')')
    {
      if (s.empty() || s.top() != '(')
      {
        return false;
      }
      s.pop();
    }
  }
  return s.empty();
}

int main()
{
  int T;
  cin >> T;
  string s;
  while (T--)
  {
    cin >> s;
    if (balanceParanthesis(s))
    {
      cout << "Balanced";
    }
    else
    {
      cout << "Unbalanced";
    }
  }
  return 0;
}