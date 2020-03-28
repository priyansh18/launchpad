#include <iostream>
using namespace std;
int multiplication(int a, int b)
{
  if (b == 0)
  {
    return 0;
  }
  return multiplication(a, b - 1) + a;
}
int main()
{
  int a, b;
  cin >> a >> b;
  if ((a > 0 && b < 0) || (a < 0 && b > 0))
  {
    cout << -1 * multiplication(abs(a), abs(b));
  }
  else
  {
    cout << multiplication(abs(a), abs(b));
  }
}