#include <bits/stdc++.h>
// #define int long long

using namespace std;
int stringToInt(char a[], int n, int i)
{
  if (i >= n)
    return 0;

  return (a[i] - '0') * pow(10, n - 1 - i) + stringToInt(a, n, i + 1);
}

int main()
{

  int n;
  cin >> n;
  char *arr = new char[n + 1];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  arr[n] = '\0';
  cout << stringToInt(arr, n, 0) << endl;
  return 0;
}