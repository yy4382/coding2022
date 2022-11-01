#include <iostream>
using namespace std;

double ctofconventer (double cdegree){
    double fdegree = 1.8*cdegree+32.0;
    return fdegree;
}

int main(){
    double cdegree;
    cin >> cdegree;
    cout << "Fahrenheit temperature is " <<ctofconventer(cdegree) << " degree" << endl;
    return 0;
}