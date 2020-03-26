#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    gcd(b, a % b);
}
int lcm(int a, int b)
{
    int lcm = (a * b) / gcd(a, b);
    return lcm;
}
int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    cout << gcd(n1, n2) << endl;
    cout << lcm(n1, n2) << endl;
}