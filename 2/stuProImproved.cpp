#include <iomanip>
#include <iostream>
using namespace std;

const int NUM=3;
struct stu
{
    int num, cls;
    double g1, g2, g3, sum,sort;
};

int main()
{
    stu stue[NUM], temp;
    for (int i = 0; i < NUM; i++)
    {
        cin >> stue[i].num >> stue[i].cls >> stue[i].g1 >> stue[i].g2 >> stue[i].g3;
        stue[i].sum = stue[i].g1 + stue[i].g2 + stue[i].g3;
        stue[i].sort=1000*stue[i].cls-stue[i].sum;
    }
    //input data
    for(int i=0; i<NUM-1; i++){
        for (int j=0;j<NUM-i-1;j++){
            if(stue[j].sort<stue[j+1].sort){
                temp=stue[j];
                stue[j]=stue[j+1];
                stue[j+1]=temp;
            }
        }
    }
    //sort
    int cls=-1;
    for(int i=0; i<NUM; i++){
        if(stue[i].cls==cls){
            cout<<";"<<stue[i].num<<","<<fixed<<setprecision(1)<<stue[i].sum;
        }
        else{
            if(i!=0) cout<<endl;
            cout<<stue[i].cls<<","<<stue[i].num<<","<<fixed<<setprecision(1)<<stue[i].sum;
        }
        cls=stue[i].cls;
    }
    cout<<endl;
    //output
    return 0;
}