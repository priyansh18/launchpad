#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int a[10] = {10, 20, 30, 40, 80, 100, 50, 60, 70, 90};
  int n = sizeof(a) / sizeof(int);
  int key;
  cin >> key;

  auto it = find(a, a + n, key);
  cout << it - a;
}
