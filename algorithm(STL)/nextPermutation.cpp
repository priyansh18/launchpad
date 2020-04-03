#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int N, a[10];
    cin >> N;
    for (int i = 0; i < N; i++)
    {
      cin >> a[i];
    }
    next_permutation(a, a + N);
    for (int i = 0; i < N; i++)
    {
      cout << a[i] << " ";
    }

    cout << endl;
  }

  return 0;
}