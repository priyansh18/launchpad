#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int m, target, arr[1000];
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> arr[i];
  }
  cin >> target;
  sort(arr, arr + m); //nlogn

  for (int i = 0; i < m; i++)
  {
    int for_pair_target = target - arr[i];
    int left = i + 1;
    int right = m - 1;
    while (left < right)
    {
      int sum = arr[left] + arr[right];
      if (sum == for_pair_target)
      {
        cout << arr[i] << " and " << arr[left] << " and " << arr[right] << endl;
        left++;
        right--;
      }
      else if (sum < for_pair_target)
      {
        left = left + 1;
      }
      else
      {
        right = right - 1;
      }
    }
  }
  return 0;
}