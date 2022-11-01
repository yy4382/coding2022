#include <cstring>
#include <iostream>
using namespace std;

struct codeconventer {
    char word[256];
    char code[256];
};

int main() {
    codeconventer a;
    cin.getline(a.code, 256);
    char co[20] = "dwk;ihmoazbnycefgjl", wo[20] = "abcdefghijklm;woyzn";
    for (int i = 0; i < 256; i++) {
        if (a.code[i] == '\0') {
            a.word[i] = '\0';
            break;
        }
        bool flag = 0;
        for (int j = 0; j < 19; j++) {
            if (a.code[i] == co[j]) {
                a.word[i] = wo[j];
                flag = 1;
            }
        }
        if (!flag) a.word[i] = a.code[i];
    }
    cout << a.word << endl;
    return 0;
}
