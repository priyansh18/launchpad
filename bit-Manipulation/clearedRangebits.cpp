#include <iostream>
using namespace std;
int clearLastIBits(int n, int i)
{
  int mask = (-1 << i);
  int answer = (n & mask);
  return answer;
}
int clearRangeBits(int n, int i, int j)
{
  int leftMask = (-1 << (j + 1));
  int rightMask = (1 << i) - 1;
  int mask = leftMask | rightMask;
  int answer = n & mask;
  return answer;
}
int main()
{
  int n, i, j;
  cin >> n;
  cin >> i;
  cin >> j;
  cout << clearLastIBits(n, i) << endl;
  cout << clearRangeBits(n, i, j);
}
