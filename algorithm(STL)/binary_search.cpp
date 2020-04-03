#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int a[10] = {10, 20, 30, 40, 40, 40, 50, 60, 70, 90};
  int n = sizeof(a) / sizeof(int);
  int key;
  cin >> key;

  bool present = binary_search(a, a + n, key);
  if (present)
  {
    cout << "present";
  }
  else
  {
    cout << "absent";
  }

  auto lb = lower_bound(a, a + n, 40);
  cout << endl
       << "lower bound of 40 is " << (lb - a) << endl;

  auto up = upper_bound(a, a + n, 40);
  cout << endl
       << "upper bound of 40 is " << (up - a) << endl;

  cout << "Occurence of element 40 is " << up - lb;
  return 0;
}