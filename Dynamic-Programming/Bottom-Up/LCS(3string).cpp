#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int lcs(char *X, char *Y, char *Z)
{
  int m = strlen(X);
  int n = strlen(Y);
  int o = strlen(Z);

  //creating table
  int L[m + 1][n + 1][o + 1];
  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      for (int k = 0; k <= o; k++)
      {
        if (i == 0 || j == 0 || k == 0)
        {
          //initialize first row and column as Zero
          L[i][j][k] = 0;
        }
        else if (X[i - 1] == Y[j - 1] && Y[j - 1] == Z[k - 1])
        {
          L[i][j][k] = L[i - 1][j - 1][k - 1] + 1;
        }
        else
        {
          L[i][j][k] = max(max(L[i - 1][j][k], L[i][j - 1][k]), L[i][j][k - 1]);
        }
      }
    }
  }
  return L[m][n][o];
}

int main()
{
  char str1[100], str2[100], str3[100];
  cin >> str1 >> str2 >> str3;
  cout << lcs(str1, str2, str3);
  return 0;
}