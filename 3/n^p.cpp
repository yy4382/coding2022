#include<iostream>
#include <cmath>
using namespace std;

int nppow(int n, int p){
    long long result=0;
    for(int i=1;i<=n;i++){
        result+=pow(i,p);
    }
    return result;
}

int main(){
    int n,p;
    cin>>n>>p;
    cout<<nppow(n,p)<<endl;
    return 0;
}