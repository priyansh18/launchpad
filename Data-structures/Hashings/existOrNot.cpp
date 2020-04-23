#include <iostream>
#include <set>
using namespace std;
int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    set<int> s;
    for (int i = 0; i < n; i++)
    {
      int k = a[i];
      s.insert(k);
    }

    int Q;
    cin >> Q;
    while (Q--)
    {
      int key;
      cin >> key;

      if (s.find(key) != s.end())
      {
        cout << "Yes";
      }
      else
      {
        cout << "No";
      }
    }

    delete[] a;
  }

  return 0;
}