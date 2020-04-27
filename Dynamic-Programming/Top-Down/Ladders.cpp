#include <iostream>
using namespace std;
int ladders(int n, int k, int dp[])
{
  //Base case
  if (n == 0)
  {
    return 1;
  }
  //lookup
  if (dp[n] != 0)
  {
    return dp[n];
  }
  int ways = 0;
  for (int i = 1; i <= k; i++)
  {
    if (n - i >= 0)
      ways += ladders(n - i, k, dp);
  }
  return ways;
}

int main()
{
  //time complexity O(nk)
  //space complexity O(n)
  int n, k;
  cin >> n >> k;
  int dp[100] = {0};
  cout << ladders(n, k, dp) << " ways" << endl;
  return 0;
}