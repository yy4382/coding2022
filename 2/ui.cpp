#include <iostream>
using namespace std;

int main(){
    char input;
    cout<<"                              1.Input\n                              2.Output\n                              3.Order\n                              4.Quit\n";
    cin >> input;
    switch (int(input))
    {
    case 105:
        cout<<"You are trying to Input info\n";
        break;
    case 111:
        cout<<"You are trying to Output info\n";
        break;
    case 109:
        cout<<"You are trying to Make things ordered\n";
        break;
    case 113:
        cout<<"You are about to Quit\n";
        break;
    default:
        cout<<"Wrong input\n";
        break;
    }
    return 0;
}