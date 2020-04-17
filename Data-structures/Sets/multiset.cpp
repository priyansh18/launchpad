#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main()
{
  // empty multiset container
  multiset<int, greater<int>> s;

  // insert elements in random order
  s.insert(40);
  s.insert(30);
  s.insert(60);
  s.insert(20);
  s.insert(50);
  s.insert(50); // 50 will be added again to the multiset unlike set
  s.insert(10);

  // printing multiset s
  multiset<int, greater<int>>::iterator itr;
  cout << "\nThe multiset s is : ";
  for (itr = s.begin(); itr != s.end(); ++itr)
  {
    cout << '\t' << *itr;
  }
  cout << endl;

  // assigning the elements from s to s2
  multiset<int> s2(s.begin(), s.end());

  // print all elements of the multiset s2
  cout << "\nThe multiset s2 after assign from s is : ";
  for (itr = s2.begin(); itr != s2.end(); ++itr)
  {
    cout << '\t' << *itr;
  }
  cout << endl;

  // remove all elements up to element with value 30 in s2
  cout << "\ns2 after removal of elements less than 30 : ";
  s2.erase(s2.begin(), s2.find(30));
  for (itr = s2.begin(); itr != s2.end(); ++itr)
  {
    cout << '\t' << *itr;
  }

  // remove all elements with value 50 in s2
  int num;
  num = s2.erase(50);
  cout << "\ns2.erase(50) : ";
  cout << num << " removed \t";
  for (itr = s2.begin(); itr != s2.end(); ++itr)
  {
    cout << '\t' << *itr;
  }

  cout << endl;

  //lower bound and upper bound for multiset s
  cout << "s.lower_bound(40) : "
       << *s.lower_bound(40) << endl;
  cout << "s.upper_bound(40) : "
       << *s.upper_bound(40) << endl;

  //lower bound and upper bound for multiset s2
  cout << "s2.lower_bound(40) : "
       << *s2.lower_bound(40) << endl;
  cout << "s2.upper_bound(40) : "
       << *s2.upper_bound(40) << endl;

  return 0;
}
