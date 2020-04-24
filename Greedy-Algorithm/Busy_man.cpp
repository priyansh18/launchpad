#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2)
{
  return p1.second < p2.second;
}

int main()
{
  int t, n, start, end;
  cin >> t;
  vector<pair<int, int>> v;
  while (t--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> start >> end;
      v.push_back(make_pair(start, end));
    }
    //Sort based on finishing time
    sort(v.begin(), v.end(), compare);
    // start picking activities
    int res = 1;
    int finish = v[0].second;
    //Iterate over remaining activities
    for (int i = 1; i < n; i++)
    {
      if (v[i].first >= finish)
      {
        finish = v[i].second;
        res++;
      }
    }
    cout << res << endl;
    v.clear();
  }
  return 0;
}