#include <iostream>
using namespace std;

int main()
{
  int a[10] = {1, 2, 3};

  cout << sizeof(a) << endl;
  int n = sizeof(a) / sizeof(int);
  cout << n << endl;

  for (int i = 0; i < 10; i++)
  {
    cout << a[i] << " ";
  }

  return 0;
}