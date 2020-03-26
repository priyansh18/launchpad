#include <iostream>
using namespace std;
void gcd(int a,int b){
    if(b==0){
        cout<<a;
    }else{
        gcd(b,a%b);
    }
}
int main() {
    int n1,n2;
    cin>>n1>>n2;
    gcd(n1,n2);
}