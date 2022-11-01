#include <cstring>
#include <iostream>
using namespace std;

bool strcpr(char* a, char* b) {
    bool flag = 0;
    int i = 0;
    while (a[i] != 0 && b[i] != 0) {
        if (int(a[i]) == int(b[i])) {
            i++;
            continue;
        }
        if ((a[i]) < int(b[i])) {
            flag = 1;
            break;
        }
        if ((a[i]) > int(b[i])) {
            flag = 0;
            break;
        }
    }
    return flag;
}

void cprstr(char* a, char* b, char* c) {
    if (strcpr(a, b)) {
        strcpy(a, b);
    }
    if (strcpr(a, c)) {
        strcpy(a, c);
    }
}

int main() {
    char a[50], b[50], c[50];
    cin.getline(a, 50);
    cin.getline(b, 50);
    cin.getline(c, 50);
    cprstr(a, b, c);
    cout << a << endl;
    return 0;
}