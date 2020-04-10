#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &s, int x)
{
  if (s.empty())
  {
    s.push(x);
    return;
  }
  int y = s.top();
  s.pop();
  insertAtBottom(s, x);
  s.push(y);
}
void reverse(stack<int> &s)
{
  if (s.empty())
  {
    return;
  }
  int x = s.top();
  s.pop();
  reverse(s);
  insertAtBottom(s, x);
}
int main()
{
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  reverse(s);
  while (!s.empty())
  {
    cout << s.top() << endl;
    s.pop();
  }

  return 0;
}