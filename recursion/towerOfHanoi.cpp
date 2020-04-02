#include <iostream>
using namespace std;
void towerOfHanoi(int n, char src, char dest, char helper)
{
  if (n == 0)
  {
    return;
  }
  //1.Move n-1 disk from source to helper
  towerOfHanoi(n - 1, src, helper, dest);
  //2.Move nth disk from source to destination
  cout << "Moving ring " << n << " from " << src << " to " << dest << endl;
  //3 .Move n-1 disk from helper destination
  towerOfHanoi(n - 1, helper, dest, src);
}

int main()
{
  int n;
  cin >> n;
  towerOfHanoi(n, 'A', 'C', 'B');

  return 0;
}