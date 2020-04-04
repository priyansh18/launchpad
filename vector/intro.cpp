#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> a;
  vector<int> b(5, 10);
  vector<int> c(b.begin(), b.end());
  vector<int> d{1, 2, 3, 4, 5};

  for (int i = 0; i < c.size(); i++)
  {
    cout << c[i] << " ";
  }
  cout << endl;
  for (auto it = b.begin(); it != b.end(); it++)
  {
    cout << (*it) << " ";
  }
  cout << endl;

  for (int x : d)
  {
    cout << x << " ";
  }

  vector<int> v;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int no;
    cin >> no;
    v.push_back(no);
  }
  for (int x : v)
  {
    cout << x << " ";
  }
  cout << endl;
  cout << v.size() << endl;
  cout << v.capacity();
  cout << v.max_size();
  cout << endl;
  cout << endl;
  cout << d.size() << endl;
  cout << d.capacity();
  cout << d.max_size();
  return 0;
}