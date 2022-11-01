#include <cstring>
#include <iostream>
using namespace std;

int main() {
    char a[10005] = {'\0'},b[10005]={'\0'};
    char ch;
    int pos = 0,i=0;
    bool flag = 1;
    cin>>b;
    while (b[i]!='\0') {
        ch=b[i];
        i++;
        if (ch == '[') {
            a[pos] = ch;
            pos++;
        } else if (ch == '(') {
            a[pos] = ch;
            pos++;
        } else if (ch == ')') {
            if (a[pos - 1] == '(') {
                pos--;
                a[pos] = '\0';
            } else {
                flag = 0;
                break;
            }
        } else if (ch == ']') {
            if (a[pos - 1] == '[') {
                pos--;
                a[pos] = '\0';
            } else {
                flag = 0;
                break;
            }
        }
    }
    if (a[0] != '\0') flag = 0;
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}