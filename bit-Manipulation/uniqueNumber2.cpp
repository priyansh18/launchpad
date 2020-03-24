#include <iostream>
using namespace std;

int main()
{
  int n;
  int a[100000];
  cin >> n;

  int no;
  int XOR = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> no;
    a[i] = no;
    XOR = XOR ^ no;
  }
  int temp = XOR;
  int pos = 0;
  while ((temp & 1) != 1)
  {
    pos++;
    temp = temp >> 1;
  }
  int mask = (1 << pos);
  int x = 0;
  int y = 0;
  for (int i = 0; i < n; i++)
  {
    if ((a[i] & mask) > 0)
    {
      x = x ^ a[i];
    }
  }
  y = XOR ^ x;
  cout << min(x, y) << " " << max(x, y);
}
