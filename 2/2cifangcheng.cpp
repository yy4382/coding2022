#include <iostream>
#include<cmath>
using namespace std;

int main(){
    double a,b,c;
    cout.precision(6);
    cin>>a>>b>>c;
    double delta=pow(b,2)-4*a*c;
    if (delta<0) cout<<"no root"<<endl;
    else if (delta>0){
        double r1,r2;
        r1=(-b-sqrt(delta))/(2*a);
        r2=(-b+sqrt(delta))/(2*a);
        if(r1<0.001&&r1>-0.0001) r1=0;
        if(r2<0.001&&r2>-0.0001) r2=0;
        cout<<r1<<" "<<r2<<endl;
    }
    else {
        if((-b)/(2*a)<0.001&&(-b)/(2*a)>-0.001) cout<<0<<endl;
        else cout<<(-b)/(2*a)<<endl;
    }
    return 0;
}