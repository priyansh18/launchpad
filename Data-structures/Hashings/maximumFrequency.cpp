#include <iostream>
#include <unordered_map>
using namespace std;
int maximumFrequencyElement(int a[], int n)
{
  unordered_map<int, int> hash;
  for (int i = 0; i < n; i++)
  {
    hash[a[i]]++;
  }

  // find the max frequency
  int max_count = 0, res = -1;
  for (auto i : hash)
  {
    if (max_count < i.second)
    {
      res = i.first;
      max_count = i.second;
    }
  }
  return res;
}

int main()
{
  int n, a[100];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cout << maximumFrequencyElement(a, n) << endl;

  return 0;
}