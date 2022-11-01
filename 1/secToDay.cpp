#include<iostream>
using namespace std;

const int hid=24;
const int mih=60;
const int sim=60;

int main(){
    long long tsec,day;
    int hour,min,sec;
    cin>>tsec;
    day=tsec/(hid*mih*sim);
    hour=tsec%(hid*mih*sim)/(mih*sim);
    min=tsec%(mih*sim)/sim;
    sec=tsec%sim;
    cout <<tsec<<" seconds = "<<day<<" days, "<<hour<<" hours, "<<min<<" minutes, "<<sec<<" seconds\n";
    return 0;
}