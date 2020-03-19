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
  for (int i = 1; i < n; i++)
  {
    int e = a[i];
    int j = i - 1;
    while (a[j] > e and j >= 0)
    {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = e;
  }
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
}
