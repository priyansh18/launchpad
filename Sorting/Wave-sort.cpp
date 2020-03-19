#include <iostream>
using namespace std;
int main()
{
  int n, a[10];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 1; i < n; i += 2)
  {
    // checking for the left element
    if (i > 0 and a[i - 1] > a[i])
    {
      swap(a[i], a[i - 1]);
    }
    // checking for the right element
    if (i < n - 1 and a[i + 1] > a[i])
    {
      swap(a[i], a[i + 1]);
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
}
