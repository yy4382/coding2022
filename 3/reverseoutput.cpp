#include <iostream>
#include <cstring>
using namespace std;
int start;
char a[20];
bool flag=0;
void reverseOutput(char*,int,int);

int main(){
    cin>>a;
    int n=strlen(a);
    if(n==1) cout<<a;
    else reverseOutput(a,0,n);
    cout<<endl;
    return 0;
}

void reverseOutput(char a[],int start,int n){
    if (start==n) return;
    reverseOutput(a,start+1,n);
    if(flag==0&&a[start]!='0') flag=1;
    if(flag==1) cout<<a[start];
}