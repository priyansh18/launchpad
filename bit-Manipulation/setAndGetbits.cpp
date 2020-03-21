#include <iostream>
using namespace std;
bool isOdd(int n)
{
  return (n & 1);
}
int getBit(int n, int i)
{
  int get;
  if ((n & (1 << i)) > 0)
  {
    get = 1;
  }
  else
  {
    get = 0;
  }
  return get;
}
int setBit(int n, int i)
{
  int set;
  int mask = (1 << i);
  set = n | mask;
  return set;
}
int clearBit(int n, int i)
{
  int mask = ~(1 << i);
  int number = n & mask;
  return number;
}
int updateBit(int n, int i, int v)
{
  int mask = ~(1 << i);
  int cleared_n = n & mask;
  int answer = cleared_n | (v << i);
  return answer;
}
int main()
{
  int n = 5;
  int i = 2;

  cout << isOdd(n) << " ";
  cout << getBit(n, i) << " ";
  cout << "Ans " << setBit(n, i) << " ";
  cout << clearBit(n, i) << " ";
  cout << updateBit(n, i, 1);
}
