#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> d{1, 2, 3, 4, 5};
  //Pushing at end
  d.push_back(19);
  //pop element from back
  d.pop_back();
  //Insert in  middle
  d.insert(d.begin() + 3, 100);
  //Insert multiple in  middle O(N)
  d.insert(d.begin() + 3, 2, 100);
  //Erase 3rd element
  d.erase(d.begin() + 3);
  // clear all element but not the capacity;
  d.clear();

  for (int x : d)
  {
    cout << x << " ";
  }

  vector<int> v;
  int n;
  cin >> n;
  v.reserve(50);
  for (int i = 0; i < n; i++)
  {
    int no;
    cin >> no;
    v.push_back(no);
    cout << v.capacity() << endl;
  }

  return 0;
}