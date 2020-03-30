#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void shuffle(int a[], int start, int end)
{
  srand(time(NULL));
  int i, j;
  for (int i = end; i > 0; i--)
  {
    j = rand() % (i + 1);
    swap(a[i], a[j]);
  }
}
int partition(int a[], int start, int end)
{
  int pivot = a[end];
  int i = start - 1;
  for (int j = start; j < end; j++)
  {
    if (a[j] <= pivot)
    {
      i++;
      swap(a[i], a[j]);
    }
  }

  swap(a[i + 1], a[end]);
  return i + 1;
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
  // shuffle(a, 0, n - 1);
  // for (int i = 0; i < n; i++)
  // {
  //   cout << a[i] << " ";
  // }
  quickSort(a, 0, n - 1);
  cout << "==============";
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }

  return 0;
}