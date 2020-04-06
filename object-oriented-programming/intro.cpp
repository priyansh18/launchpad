#include <iostream>
#include <cstring>
using namespace std;
class Car
{
private:
  int price;

public:
  int model_no;
  char name[20];
  //Constructor
  Car()
  {
    //It override the default constructor
    cout << "making a car" << endl;
  }
  // constructor with parametre --parametrised constructor
  Car(int p, int mn)
  {
    price = p;
    model_no = mn;
  }
  // Copy constructor
  Car(Car &X)
  {
    price = X.price;
    model_no = X.model_no;
    strcpy(name, X.name);
  }
  void start()
  {
    cout << "Grrrrr......" << endl;
  }
  void setPrice(int p)
  {
    price = p;
  }
  int getPrice()
  {
    return price;
  }
  void print()
  {
    // cout << name << endl;
    cout << price << endl;
    cout << model_no << endl;
    cout << endl;
  }
};
int main()
{
  Car c;
  // cout << sizeof(c) << endl;
  // cout << sizeof(Car) << endl;
  //Initialisation
  c.setPrice(500);
  c.model_no = 514;
  c.name[0] = 'A';
  c.name[1] = 'U';
  c.name[2] = 'D';
  c.name[3] = 'I';
  c.name[4] = '\0';
  c.start();
  cout << c.name << endl;
  cout << c.getPrice() << endl;

  Car e(100, 2001);
  e.print();

  Car f(e);
  f.print();
  return 0;
}