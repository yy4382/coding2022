#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char c;
    int size[3]={0};
    while(cin.get(c)){
        if(c>'0'-1&&c<='9') size[0]++;
        else if((c>=65&&c<=90)||(c>='a'&&c<='z')) size[1]++;
        else if(c==' ') size[2]++;
    }
    cout <<size[0] <<" "<< size[1] <<" "<<size[2] <<endl;
    return 0;
}