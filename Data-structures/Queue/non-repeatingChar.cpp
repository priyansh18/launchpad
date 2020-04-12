#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
  queue<char> q;
  unordered_map<char, int> map;
  char ch;
  cin >> ch;
  while (ch != '.')
  {
    q.push(ch);
    map[ch]++;
    while (!q.empty())
    {
      if (map[q.front()] > 1)
      {
        q.pop();
      }
      else
      {
        cout << q.front() << endl;
        break;
      }
      if (q.empty())
      {
        cout << "-1" << endl;
      }
      cin >> ch;
    }
  }

  return 0;
}