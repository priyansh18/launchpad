#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
  unordered_map<string, vector<string>> phonebook;
  phonebook["Rahul"].push_back("911");
  phonebook["Rahul"].push_back("922");
  phonebook["Rahul"].push_back("933");
  phonebook["Rahul"].push_back("944");
  phonebook["Kajal"].push_back("955");
  phonebook["Kajal"].push_back("966");
  phonebook["Kajal"].push_back("977");
  phonebook["Kajal"].push_back("988");

  for (auto p : phonebook)
  {
    cout << p.first << "-->";
    for (string s : p.second)
    {
      cout << s << " ,";
    }
    cout << endl;
  }

  return 0;
}