#include <iostream>
using namespace std;

int main()
{
  int n, a[100];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int load = 0;
  for (int i = 0; i < n; i++)
  {
    load = load + a[i];
  }
  if (load % n != 0)
  {
    cout << "-1";
  }
  //Load equally divided
  int max_load = 0;
  int difference = 0;
  int maximumLoad = load / n;
  for (int i = 0; i < n; i++)
  {
    difference += a[i] - maximumLoad;
    int ans = max(difference, -difference);
    max_load = max(max_load, ans);
  }
  cout << max_load;
  return 0;
}