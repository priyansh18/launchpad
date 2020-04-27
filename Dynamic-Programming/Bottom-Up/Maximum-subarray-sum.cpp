#include <iostream>
using namespace std;
int maxSum(int a[], int n)
{
  int dp[100] = {0};
  if (a[0] > 0)
  {
    dp[0] = a[0];
  }
  else
  {
    dp[0] = 0;
  }
  int max_so_far = dp[0];
  for (int i = 1; i < n; i++)
  {
    dp[i] = dp[i - 1] + a[i];
    if (dp[i] < 0)
    {
      dp[i] = 0;
    }
    max_so_far = max(dp[i], max_so_far);
  }
  return max_so_far;
}
int maxSumOptimised(int a[], int n)
{
  // space efficient without use of any other array
  int current_sum = 0;
  int max_so_far = 0;
  for (int i = 0; i < n; i++)
  {
    current_sum += a[i];
    if (current_sum < 0)
    {
      current_sum = 0;
    }
    max_so_far = max(current_sum, max_so_far);
  }
  return max_so_far;
}

int main()
{
  int n, a[100];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cout << maxSum(a, n) << endl;
  cout << maxSumOptimised(a, n) << endl;

  return 0;
}
