#include<iostream>
using namespace std;

int main(){
    int a[5],min,max;
    for(int i=0; i<5; i++) cin>> a[i];
    if (a[1]<a[2]) {int temp=a[1];a[1]=a[2];a[2]=temp;}
    if (a[3]<a[4]) {int temp=a[3];a[3]=a[4];a[4]=temp;}
    if (a[1]<a[3]) {int temp=a[1];a[1]=a[3];a[3]=temp;}
    if (a[2]<a[4]) {int temp=a[2];a[2]=a[4];a[4]=temp;}
    if (a[1]>a[0]) max=a[1];
    else max=a[0];
    if (a[4]<a[0]) min=a[4];
    else min=a[0];
    cout<<min<<" "<<max<<endl;
    return 0;
}