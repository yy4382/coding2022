#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char a[100];
    int space=0,cap=0,lower=0,num=0;
    cin.getline(a,100);
    for(int i=0;i<100;i++){
        if(a[i]=='\0') break;
        if(a[i]==' ') space++;
        if(a[i]>='A'&&a[i]<='Z') cap++;
        if(a[i]>='a'&&a[i]<='z') lower++;
        if(a[i]>='0'&&a[i]<='9') num++;
    }
    cout<<"space: "<<space<<endl;
    cout<<"capital: "<<cap<<endl;
    cout<<"lowercase: "<<lower<<endl;
    cout<<"number: "<<num<<endl;
    return 0;
}