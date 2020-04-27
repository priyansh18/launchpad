#include <iostream>
using namespace std;
int ladders(int n, int k)
{
  //Base case
  int dp[100] = {0};
  dp[0] = 1;

  for (int i = 1; i <= n; i++)
  {
    dp[i] = 0;
    for (int j = 1; j <= k; j++)
    {
      if (i - j >= 0)
      {
        dp[i] += dp[i - j];
      }
    }
  }
  return dp[n];
}
int laddersOptimised(int n, int k)
{
  int dp[100] = {0};
  dp[0] = dp[1] = 1;
  for (int i = 2; i <= k; i++)
  {
    dp[i] = 2 * dp[i - 1];
  }
  for (int i = k + 1; i <= n; i++)
  {
    dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
  }
  return dp[n];
}

int main()
{
  //time complexity O(nk)
  //space complexity O(n)
  int n, k;
  cin >> n >> k;
  cout << ladders(n, k) << " ways" << endl;
  //time complexity O(n)
  cout << laddersOptimised(n, k) << " ways" << endl;

  return 0;
}