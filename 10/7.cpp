#include <iostream>
using namespace std;

void mergesort(int a[],int b[],int re[]){
    int pa=0,pb=0,pr=0;
    while(pa<4&&pb<4){
        if(a[pa]<b[pb]){
            re[pr]=a[pa];
            pr++;
            pa++;
        } else {
            re[pr]=b[pb];
            pr++;
            pb++;
        }
    }
    if(pa==4){
        while(pb<4){
            re[pr]=b[pb];
            pr++;
            pb++;
        }
    }else{
        while(pa<4){
            re[pr]=a[pa];
            pr++;
            pa++;
        }
    }
}
int main(){
    int a[4],b[4],re[8];
    for(int i=0;i<4;i++) cin>>a[i];
    for(int i=0;i<4;i++) cin>>b[i];
    mergesort(a,b,re);
    for(int i=0;i<8;i++) cout<<re[i]<<" ";
    cout<<endl;
    return 0;
}