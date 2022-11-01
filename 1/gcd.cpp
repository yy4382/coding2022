#include <iostream>
using namespace std;

int gcd(int a,int b){
    if (a<b){int temp=a;a=b;b=temp;}
    while(a%b!=0){
        int c=a%b;
        a=b;
        b=c;
    }
    return b;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<" "<<a*b/gcd(a,b)<<endl;
    return 0;
}