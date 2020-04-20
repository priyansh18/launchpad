#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
  unordered_map<string, int> m;
  // 1.Insert
  m.insert(make_pair("Mango", 100));

  pair<string, int> p;
  p.first = "Apple";
  p.second = 200;

  m.insert(p);

  m["Banana"] = 20;
  // Update
  m["Banana"] = 40;

  m["Litchi"] = 400;

  m["Pineapple"] = 240;

  m["Kiwi"] = 240;

  for (auto it = m.begin(); it != m.end(); it++)
  {
    cout << it->first << "----" << it->second;
    cout << endl;
  }
  string fruit;
  cout << "Erase: ";
  cin >> fruit;
  m.erase(fruit);
  for (auto it = m.begin(); it != m.end(); it++)
  {
    cout << it->first << "----" << it->second;
    cout << endl;
  }

  //Erase

  string fruit1;
  cout << "Search: ";
  cin >> fruit1;
  auto it = m.find(fruit1);
  if (it != m.end())
  {
    cout << "price of " << fruit1 << " is " << m[fruit1] << endl;
  }
  else
  {
    cout << "Fruit not present";
  }
  return 0;
}