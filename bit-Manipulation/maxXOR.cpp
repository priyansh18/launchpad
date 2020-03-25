#include <iostream>
using namespace std;
int XOR(int a, int b)
{
  return a ^ b;
}
int main()
{
  int x, y, max = -99999;
  cin >> x >> y;
  for (int i = x; i < y; i++)
  {
    for (int j = i + 1; j <= y; j++)
    {
      int mid = XOR(i, j);
      if (mid > max)
      {
        max = mid;
      }
    }
  }
  cout << max;
}
