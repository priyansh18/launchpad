#include <iostream>
using namespace std;
class Car
{
private:
  int price;

public:
  int model_no;
  char name[20];

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
  return 0;
}