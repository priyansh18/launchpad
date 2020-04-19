#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void solution(double arr[], int n)
{
  // max heap to store the smaller half elements
  priority_queue<double> s;
  // min heap to store the greater half elements
  priority_queue<double, vector<double>, greater<double>> g;
  double med = arr[0];
  s.push(arr[0]);
  for (int i = 1; i <= n; i++)
  {
    double x = arr[i];

    // case1(left side heap has more elements)
    if (s.size() > g.size())
    {
      if (x < med)
      {
        g.push(s.top());
        s.pop();
        s.push(x);
      }
      else
        g.push(x);

      med = (s.top() + g.top()) / 2.0;
    }
    // case2(both heaps are balanced)
    else if (s.size() == g.size())
    {
      if (x < med)
      {
        s.push(x);
        med = (double)s.top();
      }
      else
      {
        g.push(x);
        med = (double)g.top();
      }
    }
    // case3(right side heap has more elements)
    else
    {
      if (x > med)
      {
        s.push(g.top());
        g.pop();
        g.push(x);
      }
      else
      {
        s.push(x);
      }
      med = (s.top() + g.top()) / 2.0;
    }
  }
  cout << med << " ";
}

int main()
{
  int n, T;
  double arr[100];
  cin >> T;
  cin >> n;
  while (T--)
  {
    for (int i = 0; i <= n; i++)
    {
      cin >> arr[i];
      solution(arr, i);
    }
  }
  return 0;
}