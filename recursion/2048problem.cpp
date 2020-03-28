#include <iostream>
using namespace std;

char spellings[][10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
void p2048(int n)
{
  if (n == 0)
  {
    return;
  }
  p2048(n / 10);
  cout << spellings[n % 10] << "  ";
}
int main()
{
  int n;
  cin >> n;
  p2048(n);
}