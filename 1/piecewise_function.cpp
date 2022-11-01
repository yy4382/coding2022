#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x,y;
    cin>>x;
    if(x>0) y=3*x+1;
    else if(x<0) y=pow(x,2)-1;
    else y=0;
    cout << y <<endl;
    return 0;
}