#include <iostream>
#include <algorithm>
using namespace std;
void rotate(int a[][10], int n)
{
  // for (int row = 0; row < n; row++)
  // {
  //   int startcolumn = 0;
  //   int endcolumn = n - 1;
  //   while (startcolumn < endcolumn)
  //   {
  //     swap(a[row][startcolumn], a[row][endcolumn]);
  //     startcolumn++;
  //     endcolumn--;
  //   }
  for (int i = 0; i < n; i++)
  {
    reverse(a[i], a[i] + n);
  }

  //Transpose
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i < j)
      {
        swap(a[i][j], a[j][i]);
      }
    }
  }
}

int main()
{
  int n, a[10][10];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }
  rotate(a, n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}