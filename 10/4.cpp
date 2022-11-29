#include<iostream>
#include<cstring>
using namespace std;
char diff(char a[],char b[]) {
    int as[200]={},bs[200]={};
    int i=0;
    while(a[i]!='\0'){
        as[int(a[i])]++;
        i++;
    }
    i=0;
    while(b[i]!='\0'){
        bs[int(b[i])]++;
        i++;
    }
    for(int j=0;j<200;j++){
        if(as[j]!=bs[j]){
            i=j;
            break;
        }
    }
    return char(i);
}

int main(){
    char a[200],b[200];
    cin.getline(a,200);
    cin.getline(b,200);
    cout<<diff(a,b)<<endl;
    return 0;
}