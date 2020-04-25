#include <iostream>
using namespace std;
int fib(int n, int dp[])
{
  if (n == 0 || n == 1)
  {
    return n;
  }
  //Recursive lookup
  if (dp[n] != 0)
  {
    return dp[n];
  }
  int ans = fib(n - 1, dp) + fib(n - 2, dp);
  return dp[n] = ans;
}

int main()
{
  //time complexity O(n)
  int n;
  cin >> n;
  int dp[100] = {0};
  cout << fib(n, dp) << endl;
  return 0;
}