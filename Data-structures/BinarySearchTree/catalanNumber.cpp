// C++ implementation of the approach
#include <iostream>
using namespace std;

// Function to return the count
// of unique BSTs with n keys
int uniqueBSTs(int n)
{
  int n1, n2, sum = 0;

  // Base cases
  if (n == 1 || n == 0)
    return 1;
  // Find the nth Catalan number
  for (int i = 1; i <= n; i++)
  {

    // Recursive calls
    n1 = uniqueBSTs(i - 1);
    n2 = uniqueBSTs(n - i);
    sum += n1 * n2;
  }

  // Return the nth Catalan number
  return sum;
}

// Driver code
int main()
{
  int n;
  cin >> n;

  cout << uniqueBSTs(n);

  return 0;
}