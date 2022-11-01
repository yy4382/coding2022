#include <iostream>
using namespace std;
int main(){
    int num,a,b,c;
    bool flag=0;
    cin>>a>>b>>c;
    for(num=10;num<=100;num++){
        if(num%3==a&&num%5==b&&num%7==c){
            flag=1;
            break;
        }
    }
    if(!flag) cout<<"No answer"<<endl;
    else cout<<num<<endl;
    return 0;
}