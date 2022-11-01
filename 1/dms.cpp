#include <iostream>
using namespace std;
const int binary=60;

float dmsConventer(float degree, float minute, float second ){
    float dms;
    int bin=binary*binary;
    dms=degree+minute/binary+second/bin;
    return dms;
}

int main(){
    float degree,min,sec, result;
    cin >> degree >> min >> sec ;
    result=dmsConventer(degree,min,sec);
    cout << degree << " degrees, " << min << " minutes, " << sec << " seconds = " << result << " degrees\n";
    return 0;
}