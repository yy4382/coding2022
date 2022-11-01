#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long a, f2 = 0,f5=0,tmp;
    cin >> a;
    for (long long i=a; i >= 1; i--)
    {
        tmp=i;
        while(tmp%2==0){
            tmp=tmp/2;
            f2++;
        }
    }
    for (long long i=a; i >= 1; i--)
    {
        tmp=i;
        while(tmp%5==0){
            tmp=tmp/5;
            f5++;
        }
    }
    if(f2<f5) cout<<f2<<endl;
    else cout<<f5<<endl;
    return 0;
}