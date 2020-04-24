#include <iostream>
#include <algorithm>
using namespace std;
int make_change(int coins[], int n, int money)
{
  int ans = 0;
  while (money > 0)
  {
    int index = upper_bound(coins, coins + n, money) - 1 - coins;
    money = money - coins[index];
    ans++;
  }
  return ans;
}

int main()
{
  int n, coins[100];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }
  int money;
  cin >> money;
  cout << "Total No. of Coins: " << make_change(coins, n, money);
  return 0;
}