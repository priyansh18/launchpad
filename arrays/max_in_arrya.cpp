#include <iostream>
using namespace std;
int main()
{
  int m, arr[10];
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> arr[i];
  }
  int max = INT8_MIN;
  for (int j = 0; j < m; j++)
  {
    if (max < arr[j])
    {
      max = arr[j];
    }
  }
  cout << max;
}