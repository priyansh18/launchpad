#include <iostream>
using namespace std;
int binarySearch(int a[], int start, int end, int key)
{

  if (start > end)
  {
    return -1;
  }
  int mid = (start + end) / 2;
  if (a[mid] < key)
  {
    start = mid + 1;
    return binarySearch(a, start, end, key);
  }
  else if (a[mid] > key)
  {
    end = mid - 1;
    return binarySearch(a, start, end, key);
  }
  else
  {
    return mid;
  }
}

int main()
{
  int n, a[100], key;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cin >> key;
  cout << binarySearch(a, 0, n - 1, key);

  return 0;
}