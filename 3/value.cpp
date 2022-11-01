#include <iostream>
using namespace std;
long long value(int f1,int f2,int a,int b,int c,int n){
    if(n==1) return f1;
    if(n==2) return f2;
    long long result=a*(value(f1,f2,a,b,c,n-2))+b*(value(f1,f2,a,b,c,n-1))+c;
    return result;
}
int main(){
    int f1,f2,a,b,c,n;
    cin>>f1>>f2>>a>>b>>c>>n;
    long long modresult=value(f1,f2,a,b,c,n)%1000007;
    if(modresult<0)modresult+=1000007;
    cout<<modresult<<endl;
    return 0;
}