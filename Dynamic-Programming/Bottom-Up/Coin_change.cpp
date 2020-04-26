#include <iostream>
using namespace std;
int minCoins(int n, int coins[], int T)
{
  int dp[100] = {0};
  dp[0] = 0;

  for (int k = 1; k <= n; k++)
  {
    dp[k] = INT_FAST16_MAX;
    for (int i = 0; i < T; i++)
    {
      if (k - coins[i] >= 0)
      {
        int subprob = dp[k - coins[i]];
        dp[k] = min(dp[k], subprob + 1);
      }
    }
  }
  return dp[n];
}

int main()
{
  //complexity O(Tn)
  int T;
  cin >> T;
  int coins[] = {1, 7, 10};
  int dp[100] = {0};
  int n;
  cin >> n;
  cout << minCoins(n, coins, T);

  return 0;
}