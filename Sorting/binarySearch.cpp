#include <iostream>
using namespace std;
int main()
{
  int n, a[100], key;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cin >> key;
  int start = 0;
  int end = n - 1;
  while (start <= end)
  {
    int mid = (start + end) / 2;
    if (a[mid] == key)
    {
      cout << "element found at index " << mid;
      break;
    }
    else if (a[mid] < key)
    {
      start = mid + 1;
    }
    else if (a[mid] > key)
    {
      end = mid - 1;
    }
  }

  if (start > end)
  {
    cout << "element not found";
  }
}
