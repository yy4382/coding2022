#include <iostream>
#include<iomanip>
using namespace std;
struct stu
{
    string num;
    float a,b,c,sum;
};


int main(){
    stu stue[3];
    for(int i=0;i<3;i++){
        cin>>stue[i].num>>stue[i].a>>stue[i].b>>stue[i].c;
        stue[i].sum=stue[i].a+stue[i].b+stue[i].c;
    }
    for(int i=0;i<3;i++){
        cout<<stue[i].num<<fixed << setprecision(1)<<"  "<<stue[i].a<<"  "<<stue[i].b<<"  "<<stue[i].c<<"  "<<stue[i].sum<<endl;
    }
    return 0;
}