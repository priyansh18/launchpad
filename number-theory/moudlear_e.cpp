#include <iostream>
using namespace std;

int main()
{
  long long int a;
  cin >> a;
  long long int b;
  cin >> b;
  long long int mod;
  cin >> mod;

  if (b == 0)
  {
    cout << 1 << endl;
  }
  else
  {
    long long int ans = 1;
    while (b--)
    {
      ans = (ans * a) % mod;
    }
    cout << ans << endl;
  }

  return 0;
}
