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
    map<T, int> distance;
    queue<int> q;
    for (auto node_pair : l)
    {
      T node = node_pair.first;
      distance[node] = INT16_MAX;
    }
    q.push(source);
    distance[source] = 0;
    while (!q.empty())
    {
      T node = q.front();
      q.pop();
      for (int nbr : l[node])
      {
        if (distance[nbr] == INT16_MAX)
        {
          q.push(nbr);
          distance[nbr] = distance[node] + 1;
        }
      }
    }
    for (auto node_pair : l)
    {
      T node = node_pair.first;
      int d = distance[node];
      cout << "Node " << node << "is distance " << d << " from source " << endl;
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