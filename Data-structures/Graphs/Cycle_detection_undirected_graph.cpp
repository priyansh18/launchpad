#include <iostream>
#include <list>
using namespace std;
class Graph
{
  int v;
  list<int> *l;

public:
  Graph(int v)
  {
    this->v = v;
    l = new list<int>[v];
  }

  void addEdge(int x, int y)
  {
    l[x].push_back(y);
    l[y].push_back(x);
  }
  bool cycle_helper(int node, bool *visited, int parent)
  {

    visited[node] = true;
    for (int nbr : l[node])
    {
      if (!visited[nbr])
      {
        bool cycle_found = cycle_helper(nbr, visited, node);
        if (cycle_found == true)
        {
          return true;
        }
      }
      else if (nbr != parent)
      {
        return true;
      }
    }
    return false;
  }

  bool contains_cycle()
  {

    bool *visited = new bool[v];
    bool *stack = new bool[v];

    for (int i = 0; i < v; i++)
    {
      visited[i] = false;
    }

    return cycle_helper(0, visited, -1);
  }
};

int main()
{
  Graph g(5);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  // g.addEdge(4, 0);
  if (g.contains_cycle())
  {
    cout << "Yes cycle is present";
  }
  else
  {
    cout << "Cycle is not present";
  }
  return 0;
}