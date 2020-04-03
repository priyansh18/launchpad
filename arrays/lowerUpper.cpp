#include <iostream>
#include <cctype>
using namespace std;
int main()
{
  char x;
  cin >> x;
  if (isupper(x))
  {

    cout << "UPPERCASE";
  }
  else if (islower(x))
  {
    cout << "lowercase";
  }
  else
  {
    cout << "Invalid";
  }

  return 0;
}
