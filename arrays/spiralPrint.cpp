#include <iostream>
using namespace std;
void spiralPrint(int a[][6], int m, int n)
{
  int startRow = 0;
  int startColumn = 0;
  int endRow = m - 1;
  int endColumn = n - 1;

  while (startRow <= endRow && startColumn <= endColumn)
  {
    //First Row
    for (int i = startColumn; i <= endColumn; i++)
    {
      cout << a[startRow][i] << " ";
    }
    startRow++;
    //End Column
    for (int i = startRow; i <= endRow; i++)
    {
      cout << a[i][endColumn] << " ";
    }
    endColumn--;
    //End Row
    if (endRow > startRow)
    {
      for (int i = endColumn; i >= startColumn; i--)
      {
        cout << a[endRow][i] << " ";
      }
      endRow--;
    }
    // First Column
    if (endColumn > startColumn)
    {
      for (int i = endRow; i >= startRow; i--)
      {
        cout << a[i][startColumn] << " ";
      }
      startColumn++;
    }
  }
}
int main()
{
  int a[4][6] = {{1, 2, 3, 4, 5, 6},
                 {7, 8, 9, 10, 11, 12},
                 {13, 14, 15, 16, 17, 18},
                 {19, 20, 21, 22, 23, 24}};

  spiralPrint(a, 4, 6);
  return 0;
}