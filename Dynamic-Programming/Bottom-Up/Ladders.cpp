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

int main()
{
  //time complexity O(nk)
  //space complexity O(n)
  int n, k;
  cin >> n >> k;
  cout << ladders(n, k) << " ways" << endl;
  return 0;
}