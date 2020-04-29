#include <iostream>
#include <list>
#include <queue>
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

  bool isTree(int src)
  {
    bool *visited = new bool[v];
    int *parent = new int[v];
    queue<int> q;

    for (int i = 0; i < v; i++)
    {
      visited[i] = false;
      parent[i] = i;
    }
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
      int node = q.front();
      q.pop();

      for (int nbr : l[node])
      {
        if (visited[nbr] == true && parent[node] != nbr)
        {
          return false;
        }
        else if (!visited[nbr])
        {
          visited[nbr] = true;
          parent[nbr] = node;
          q.push(nbr);
        }
      }
    }
    return true;
  }
};

int main()
{
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  if (g.isTree(0))
  {
    cout << "yes its a tree";
  }
  else
  {
    cout << "Not a tree";
  }
  return 0;
}