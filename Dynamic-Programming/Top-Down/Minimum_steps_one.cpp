#include <iostream>
using namespace std;
//Minimum steps to One
// n-> n/3,n/2,n-1
int minSteps(int n, int dp[])
{
  //Base case
  if (n == 1)
  {
    return 0;
  }
  if (dp[n] != 0)
  {
    return dp[n];
  }
  //Rec case;
  int op1, op2, op3;
  op1 = op2 = op3 = INT_FAST16_MAX;

  if (n % 3 == 0)
  {
    op1 = minSteps(n / 3, dp);
  }
  if (n % 2 == 0)
  {
    op2 = minSteps(n / 2, dp);
  }
  op3 = minSteps(n - 1, dp);

  int ans = min(min(op1, op2), op3) + 1;
  return dp[n] = ans;
}

int main()
{
  int n;
  cin >> n;
  int dp[100] = {0};
  cout << minSteps(n, dp);
  return 0;
}