#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=0;
    int x=n-1,y=0,c=1;
    a[y][x]=c;
    while(c<n*n){
        while(a[y+1][x]==0&&y<n-1){
            y++;
            c++;
            a[y][x]=c;
        }
        while(a[y][x-1]==0&&x>0){
            x--;
            c++;
            a[y][x]=c;
        }
        while(a[y-1][x]==0&&y>0){
            y--;
            c++;
            a[y][x]=c;
        }
        while(a[y][x+1]==0&&x<n-1){
            x++;
            c++;
            a[y][x]=c;
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j];
            if(j==n-1) cout<<endl;
            else cout<<" ";
        }
    return 0;
}