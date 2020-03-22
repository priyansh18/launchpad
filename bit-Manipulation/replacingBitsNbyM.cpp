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
  int n, i, j, m;
  cin >> n;
  cin >> m;
  cin >> i;
  cin >> j;
  int n_ = clearRangeBits(n, i, j);
  int mask = m << i;
  int answer = n_ | mask;
  cout << answer;
}