#include <iostream>
#include <cstring>
using namespace std;
class Node
{
public:
  string key;
  int value;
  Node *next;
  //Constructor
  Node(string key, int val)
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
};
class Hashtable
{
  Node **table; //pointing ro array of pointers
  int current_size;
  int table_size;

  int hashFunction(string key)
  {
    int index = 0;
    int p = 1;
    for (int j = 0; j < key.length(); j++)
    {
      index += (key[j] * p) % table_size;
      index = index % table_size;
      p = (p * 27) % table_size;
    }
    return index;
  }

public:
  Hashtable(int ts = 7)
  {
    table_size = ts;
    table = new Node *[table_size];
    current_size = 0;
    for (int i = 0; i < table_size; i++)
    {
      table[i] = NULL;
    }
  }

  void insert(string key, int value)
  {
    int index = hashFunction(key);
    Node *n = new Node(key, value);
    n->next = table[index];
    table[index] = n;
    current_size++;
  }
  int *search(string key)
  {
    int index = hashFunction(key);
    Node *temp = table[index];
    while (temp != NULL)
    {
      if (temp->key == key)
      {
        return &temp->value;
      }
      return NULL;
    }
  }
  int &operator[](string key)
  {
    int *f = search(key);
    if (f == NULL)
    {
      // Insert key,value(garbage) in hashmap
      int garbage;
      insert(key, garbage);
      f = search(key);
    }
    return *f;
  }

  void print()
  {
    for (int i = 0; i < table_size; i++)
    {
      cout << "Bucket" << i << "-->";
      Node *temp = table[i];
      while (temp != NULL)
      {
        cout << temp->key << " ->";
        temp = temp->next;
      }
      cout << endl;
    }
  }
};

int main()
{
  Hashtable price_menu;
  price_menu.insert("Burger", 120);
  price_menu.insert("Pepsi", 20);
  price_menu.insert("BurgerPizza", 150);
  price_menu.insert("Noodles", 25);
  price_menu.insert("Coke", 40);

  price_menu.print();
  int *price = price_menu.search("Noodles");
  if (price == NULL)
  {
    cout << "Price not found.";
  }
  else
  {
    cout << "Price:" << *price << endl;
    ;
  }
  price_menu["Dosa"] = 60;
  price_menu["Dosa"] += 10;
  cout << "Price of Dosa:";
  cout << price_menu["Dosa"];

  return 0;
}