#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int abs(int i, int j)
{
  if (i - j > 0)
  {
    return i - j;
  }
  return j - i;
}
int main()
{
  int a[100000] = {0};
  int t, n, rank;
  cin >> t;
  while (t--)
  {
    memset(a, 0, sizeof a);
    string name;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> name >> rank;
      a[rank]++;
    }
    //Assign team nearest rank available
    int actual_rank = 1;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
      while (a[i])
      {
        sum = sum + abs(actual_rank, i);
        a[i]--;
        actual_rank++;
      }
    }
    cout << sum << endl;
  }

  return 0;
}