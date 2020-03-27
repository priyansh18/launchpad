#include <iostream>
using namespace std;
bool isSorted(int *a, int n)
{
  if (n == 1)
  {
    return true;
  }
  if (a[0] < a[1] && isSorted(a + 1, n - 1))
  {
    return true;
  }
  return false;
}
int main()
{
  int n, a[100];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  if (isSorted(a, n))
  {
    cout << "Yes Sorted";
  }
  else
  {
    cout << "Not Sorted";
  }
}
