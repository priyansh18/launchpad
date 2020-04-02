#include <iostream>
using namespace std;

int main()
{
  int n, a[100], sum;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cin >> sum;
  int i = 0;
  int j = n - 1;
  while (i < j)
  {
    if ((a[i] + a[j]) < sum)
    {
      i++;
    }
    else if ((a[i] + a[j]) > sum)
    {
      j++;
    }
    else
    {
      cout << a[i] << "," << a[j] << endl;
      i++;
      j--;
    }
  }

  return 0;
}