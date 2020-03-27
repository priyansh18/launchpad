#include <iostream>
using namespace std;

bool isPrime(int n)
{
  if (n == 1)
  {
    return false;
  }
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  return true;
}
int prime(int n)
{
  for (int i = 1; i <= n; i++)
  {
    if (isPrime(i))
    {
      cout << i << " ";
    }
  }
}
int main()
{
  int n;
  cin >> n;
  prime(n);
}