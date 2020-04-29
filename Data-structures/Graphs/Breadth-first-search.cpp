#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;
template <typename T>
class Graph
{
  map<T, list<T>> l;

public:
  void addEdge(int x, int y)
  {
    l[x].push_back(y);
    l[y].push_back(x);
  }

  void bfs(T source)
  {
    map<T, int> visited;
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
      T node = q.front();
      q.pop();
      cout << node << " ";
      for (int nbr : l[node])
      {
        if (!visited[nbr])
        {
          q.push(nbr);
          visited[nbr] = true;
        }
      }
    }
  }
};

int main()
{
  Graph<int> g;
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.bfs(0);

  return 0;
}