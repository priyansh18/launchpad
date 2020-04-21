#include <iostream>
#include <unordered_map>
using namespace std;
int LongestSubarrayWithSumK(int a[], int n, int k)
{
  unordered_map<int, int> s;
  int prefix = 0;
  int length = 0;
  for (int i = 0; i < n; i++)
  {
    prefix = prefix + a[i];
    if (prefix == k)
    {
      length = max(length, i + 1);
    }
    if (s.find(prefix - k) != s.end())
    {
      length = max(length, i - s[prefix - k]);
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
  int n, a[100], k;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cin >> k;
  cout << LongestSubarrayWithSumK(a, n, k);

  return 0;
}