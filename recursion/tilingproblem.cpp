#include <iostream>
using namespace std;
int totalWays(int n)
{
  if (n <= 3)
  {
    return 1;
  }
  if (n == 4)
  {
    return 2;
  }
  return totalWays(n - 1) + totalWays(n - 4);
}
// total number of ways in placing 4*1 tiles on 4*N size wall
int main()
{
  int n;
  cin >> n;
  cout << totalWays(n) << " ";
}