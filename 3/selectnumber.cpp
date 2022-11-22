#include <iostream>
using namespace std;
int cnt,result[10];

void selnum(int r,int k){
    if(cnt==r){
        for(int j=0;j<r;j++) cout<<result[j];
        cout<<endl;
        return;
    }
    for(int i=k;i>0;i--){
        result[cnt]=i;
        cnt++;
        selnum(r,i-1);
        cnt--;
    }
}

int main(){
    int n,r;
    cin>>n>>r;
    selnum(r,n);
    return 0;
}