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

  void addEdge(int x, int y, bool directed = true)
  {
    l[x].push_back(y);
    if (!directed)
    {
      l[y].push_back(x);
    }
  }
  bool cycle_helper(int node, bool *visited, bool *stack)
  {

    visited[node] = true;
    stack[node] = true;
    for (int nbr : l[node])
    {
      if (stack[nbr] == true)
      {
        return true;
      }
      else if (visited[nbr] == false)
      {
        bool cycle_found = cycle_helper(nbr, visited, stack);
        if (cycle_found == true)
        {
          return true;
        }
      }
    }
    stack[node] = false;
    return false;
  }

  bool contains_cycle()
  {

    bool *visited = new bool[v];
    bool *stack = new bool[v];

    for (int i = 0; i < v; i++)
    {
      visited[i] = stack[i] = false;
    }

    return cycle_helper(0, visited, stack);
  }
};

int main()
{
  Graph g(7);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 5);
  g.addEdge(1, 5);
  g.addEdge(5, 6);
  g.addEdge(4, 2);
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