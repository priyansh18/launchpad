#include <iostream>
using namespace std;
void subsequences(char in[], char out[], int i, int j)
{
  // Base Case
  if (in[i] == '\0')
  {
    out[j] = '\0';
    cout << out << ' ';
    return;
  }
  //Recursive Case
  out[j] = in[i];
  // Include the current character
  subsequences(in, out, i + 1, j + 1);
  // Exclude the current character
  subsequences(in, out, i + 1, j);
}

int main()
{
  char in[100];
  cin >> in;
  char out[100];
  subsequences(in, out, 0, 0);
  return 0;
}