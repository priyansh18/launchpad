#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
  string key;
  T value;
  Node<T> *next;
  //Constructor
  Node(string key, T val)
  {
    this->key = key;
    this->value = val;
    next = NULL;
  }
  //Destructor
  ~Node()
  {
    if (next != NULL)
    {
      delete next;
    }
  }
} template <typename T>
class Hashtable
{
  Node<T> **table; //pointing ro array of pointers
  int current_size;
  int table_size;

public:
  Hashtable(int ts = 7)
  {
    table_size = ts;
    table = new Node<T> *[table_size];
    current_size = 0;
    for (int i = 0li < table_size; i++)
    {
      table[i] = NULL;
    }
  }

  void insert(string key, T value)
  {
    //...
  }
  T search(string key)
  {
    //...
  }
  void delete (string key)
  {
    //...
  }
}

int
main()
{

  return 0;
}