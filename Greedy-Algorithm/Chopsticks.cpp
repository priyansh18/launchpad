#include <iostream>
#include <algorithm>
using namespace std;
int abs(int i, int j)
{
  if (i - j > 0)
  {
    return i - j;
  }
  return j - i;
}

int main()
{
  int n, d, a[100001];
  cin >> n >> d;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  sort(a, a + n);
  int count = 0;
  for (int i = 0; i < n - 1;)
  {
    if (a[i + 1] - a[i] <= d)
    {
      count++;
      i = i + 2;
    }
    else
    {
      i = i + 1;
    }
  }
  cout << count;

  return 0;
}