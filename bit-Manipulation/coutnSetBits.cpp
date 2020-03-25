#include <iostream>
using namespace std;
void countSetBit(int n)
{
  int count = 0;
  while (n > 0)
  {
    int last_bit = (n & 1);
    if (last_bit == 1)
    {
      count++;
    }
    n = n >> 1;
  }
  cout << count << endl;
}
int main()
{
  int n, a;
  cin >> n;

  while (n--)
  {
    cin >> a;
    countSetBit(a);
  }
}
