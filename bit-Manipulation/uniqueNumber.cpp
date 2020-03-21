#include <iostream>
using namespace std;
int main()
{
  int n, ans = 0, number;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> number;
    ans = ans ^ number;
  }
  cout << ans;
}
