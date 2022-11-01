#include <cstring>
#include <iostream>
using namespace std;
struct ani {
    string name;
    int num;
    bool ifbiggest;
};

int main() {
    int n;
    cin >> n;
    ani an[n]{};
    int pos = 0;
    string in;
    for (int i = 0; i < n; i++) {
        int flag = 0;
        cin >> in;
        for (int j = 0; j < pos; j++) {
            if (in == an[j].name) {
                an[j].num++;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            an[pos].name = in;
            an[pos].num++;
            pos++;
        }
    }
    int biggest = an[0].num;
    for (int i = 0; i < n; i++) {
        if (an[i].num == biggest) {
            an[i].ifbiggest = 1;
        } else if (an[i].num > biggest) {
            an[i].ifbiggest = 1;
            biggest = an[i].num;
            for (int j = 0; j < i; j++) an[j].ifbiggest = 0;
        }
    }
    for (int i = 0; i < n; i++)
        if (an[i].ifbiggest) cout << an[i].name << " " << an[i].num << endl;
    return 0;
}