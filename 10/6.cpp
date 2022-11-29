#include <cstring>
#include <iostream>
using namespace std;

int main() {
    char ori[100]{};
    cin >> ori;
    int p1 = 0, p2 = 0;
    char com[100]{};
    int cnt[100]{};
    while (ori[p1] != '\0') {
        int i = 1;
        com[p2] = ori[p1];
        while (ori[p1] == ori[p1 + 1]) {
            cnt[p2]++;
            p1++;
        }
        p2++;
        p1++;
    }
    bool flag = 0;
    for (int i = 0; i < 100; i++) {
        if (cnt[i] >= 2) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        int i = 0;
        while (com[i] != '\0') {
            if (cnt[i] == 0)
                cout << com[i];
            else
                cout << com[i] << cnt[i] + 1;
            i++;
        }
        cout << endl;
    } else
        cout << ori << endl;
    return 0;
}