#include <iostream>
using namespace std;
void bubbleSort(int a[], int n)
{
  if (n == 1)
  {
    return;
  }
  for (int i = 0; i < n - 1; i++)
  {
    if (a[i] > a[i + 1])
    {
      swap(a[i], a[i + 1]);
    }
  }
  bubbleSort(a, n - 1);
}
void bubbleSort2(int a[], int n, int i)
{
  if (n == 1)
  {
    return;
  }
  if (i == n - 1)
  {
    return bubbleSort2(a, n - 1, 0);
  }

  if (a[i] > a[i + 1])
  {
    swap(a[i], a[i + 1]);
  }

  bubbleSort2(a, n, i + 1);
}

int main()
{
  int n, a[100];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  bubbleSort(a, n);
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  bubbleSort2(a, n, 0);
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }

  return 0;
}