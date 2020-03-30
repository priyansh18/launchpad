#include <iostream>
using namespace std;
int partition(int a[], int start, int end)
{
  int i = start - 1;
  int j = start;
  int pivot = a[end];
  for (; j < end; j++)
  {
    if (a[j] <= pivot)
    {
      i++;
      swap(a[i], a[j]);
    }
  }
  swap(a[i + 1], a[end]);
}
void quickSort(int a[], int start, int end)
{
  if (start >= end)
  {
    return;
  }
  int p = partition(a, start, end);
  quickSort(a, start, p - 1);
  quickSort(a, p + 1, end);
}

int main()
{
  int n, a[100];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  quickSort(a, 0, n - 1);
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }

  return 0;
}