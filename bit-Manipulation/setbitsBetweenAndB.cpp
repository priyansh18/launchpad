#include <iostream>
using namespace std;
int numberOfSetBits(int n)
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
  return count;
}
void totalSetBits(int a, int b)
{
  int total = 0;
  for (int i = a; i <= b; i++)
  {
    total += numberOfSetBits(i);
  }
  cout << total << endl;
}
int main()
{
  int Q;
  cin >> Q;

  int a, b;
  // time complexity : Q(b-a)logb
  while (Q--)
  {
    cin >> a >> b;
    totalSetBits(a, b);
  }
}
