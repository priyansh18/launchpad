#include <iostream>
using namespace std;
int countBit(int n)
{
  int count = 0;
  while (n > 0)
  {
    count = count + (n & 1);
    n = n >> 1;
  }
  return count;
}
int countBit2(int n)
{
  int count = 0;
  while (n > 0)
  {
    n = n & (n - 1);
    count++;
  }
  return count;
}
int main()
{
  int n;
  cin >> n;
  cout << countBit(n) << endl;
  cout << countBit2(n) << endl;
  cout << __builtin_popcount(n) << endl;
}
