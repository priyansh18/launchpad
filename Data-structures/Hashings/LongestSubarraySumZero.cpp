#include <iostream>
#include <unordered_map>
using namespace std;
int LongestSubarrayWithSumZero(int a[], int n)
{
  unordered_map<int, int> s;
  int prefix = 0;
  int length = 0;
  for (int i = 0; i < n; i++)
  {
    prefix = prefix + a[i];
    if (a[i] == 0 || length == 0)
    {
      length = 1;
    }
    if (prefix == 0)
    {
      length = max(length, i + 1);
    }
    if (s.find(prefix) != s.end())
    {
      length = max(length, i - s[prefix]);
    }
    else
    {
      s[prefix] = i;
    }
  }
  return length;
}

int main()
{
  // time complexity = O(n)
  int n, a[100];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cout << LongestSubarrayWithSumZero(a, n);

  return 0;
}