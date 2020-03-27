#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n)
{
  int arraySize = 5000000;
  bool prime[arraySize + 1];
  prime[0] = false;
  prime[1] = false;
  for (int i = 2; i <= arraySize; i++)
  {
    prime[i] = true;
  }

  for (int p = 2; p * p <= arraySize; p++)
  {
    if (prime[p] == true)
    {
      for (int i = p * p; i <= arraySize; i += p)
        prime[i] = false;
    }
    it
  }

  // Print all prime numbers
  int count = 0;
  for (int p = 2; p <= arraySize; p++)
  {
    if (prime[p])
    {
      count++;
    }
    if (count == n)
    {
      cout << p;
      break;
    }
  }
}

int main()
{
  int n;
  cin >> n;
  SieveOfEratosthenes(n);
  return 0;
}