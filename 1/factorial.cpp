#include <iostream>
using namespace std;

int main(){
    long long a,b=1;
    cin>>a;
    for(;a>=1;a--){
        b=b*a;
    }
    cout<<b<<endl;
    return 0;
}