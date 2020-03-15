#include <iostream>
using namespace std;
int main()
{
  int m, target, arr[10000];
  cin >> m;

  for (int i = 0; i < m; i++)
  {
    cin >> arr[i];
  }
  cin >> target;
  // O(m^2) time // O(1) space
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i != j && arr[i] + arr[j] == target)
      {
        cout << arr[i] << " and " << arr[j] << endl;
      }
    }
  }
}