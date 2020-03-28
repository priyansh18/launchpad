#include <iostream>
using namespace std;
void linearSearch(int a[], int n, int key)
{
  if(n==0){
    cout << "Element Not found";
    return;
    
  }
  if (a[0] == key)
  {
    cout << "Element found";
    return;
  }
  return linearSearch(a+1, n-1, key);
}

int main()
{
  int n, a[100], key;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cin >> key;
  linearSearch(a, n, key);

  return 0;
}