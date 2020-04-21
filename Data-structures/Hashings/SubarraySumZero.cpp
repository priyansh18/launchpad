#include <iostream>
#include <unordered_set>
using namespace std;
bool checkIfSubarrayWithSumZero(int a[], int n)
{
  unordered_set<int> s;
  int prefix = 0;
  for (int i = 0; i < n; i++)
  {
    prefix = prefix + a[i];
    if (prefix == 0 || s.find(prefix) != s.end())
    {
      return true;
    }
    s.insert(prefix);
  }
  return false;
}

int main()
{
  int n, a[100];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  bool b = checkIfSubarrayWithSumZero(a, n);
  if (b == 0)
  {
    cout << "No";
  }
  else
  {
    cout << "Yes";
  }

  return 0;
}