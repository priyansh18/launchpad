#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
template <typename T>
class Graph
{
  unordered_map<T, list<pair<T, int>>> m;

public:
  void addEdge(T u, T v, int distance, bool bidirectional = true)
  {
    m[u].push_back(make_pair(v, distance));
    if (bidirectional)
    {
      m[v].push_back(make_pair(u, distance));
    }
  }
  void printAdj()
  {
    for (auto j : m)
    {
      cout << j.first << "-->";
      for (auto l : j.second)
      {
        cout << "(" << l.first << "," << l.second << ")";
      }
      cout << endl;
    }
  }
  void dijkstra(int src)
  {
    unordered_map<T, int> distance;
    for (auto j : m)
    {
      distance[j.first] = INT16_MAX;
    }
    // make a set to find out node with minimum distance
    set<pair<int, T>> s;
    s.insert(make_pair(0, src));

    while (!s.empty())
    {
      auto p = *(s.begin());
      T node = p.second;

      int nodeDist = p.first;
      s.erase(s.begin());

      for (auto childpair : m[node])
      {
        if (nodeDist + childpair.second < distance[childpair.first])
        {
          T dest = childpair.first;
          auto f = s.find(make_pair(distance[dest], dest));
          if (f != s.end())
          {
            s.erase(f);
          }
          distance[dest] = nodeDist + childpair.second;
          s.insert(make_pair(distance[dest], dest));
        }
      }
    }
    for (auto d : distance)
    {
      cout << d.first << " is located at distance of " << d.second << endl;
    }
  }
};
int main()
{
  Graph<int> g;
  g.addEdge(1, 2, 1);
  g.addEdge(1, 3, 4);
  g.addEdge(2, 3, 1);
  g.addEdge(3, 4, 2);
  g.addEdge(1, 4, 7);
  g.dijkstra(1);

  return 0;
}