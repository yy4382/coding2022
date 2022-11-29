#include <iostream>
using namespace std;
int main() {
    int n,sum;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>sum;
    int a=-1,b=-1;
    bool flag=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==sum){
                a=i;
                b=j;
                flag=1;
                break;
            }
        }
        if(flag)break;
    }
    cout<<"["<<a<<","<<b<<"]"<<endl;
    return 0;
}