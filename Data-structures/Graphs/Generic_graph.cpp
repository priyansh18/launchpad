#include <iostream>
#include <unordered_map>
#include <cstring>
#include <list>
using namespace std;
class Graph
{
  unordered_map<string, list<pair<string, int>>> l;

public:
  void addEdge(string X, string Y, bool bidirectional, int weight)
  {
    l[X].push_back(make_pair(Y, weight));
    if (bidirectional)
    {
      l[Y].push_back(make_pair(X, weight));
    }
  }

  void printList()
  {
    for (auto p : l)
    {
      string city = p.first;
      list<pair<string, int>> nbrs = p.second;
      cout << city << "->";
      for (auto nbr : nbrs)
      {
        string des = nbr.first;
        int dist = nbr.second;
        cout << des << " " << dist << ",";
      }
      cout << endl;
    }
  }
};

int main()
{
  Graph g;
  g.addEdge("A", "B", true, 20);
  g.addEdge("B", "D", true, 40);
  g.addEdge("A", "C", true, 10);
  g.addEdge("C", "D", true, 40);
  g.addEdge("A", "D", false, 50);
  g.printList();

  return 0;
}