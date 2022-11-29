#include <cstring>
#include <iostream>
using namespace std;
struct word {
    string name;
    int num;
};

int main() {
    word an[100]{};
    int pos = 0;
    string in;
    while (cin >> in) {
        int flag = 0;
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
    word* biggest = an;
    for (int i = 0; i < 100; i++) {
        if (an[i].num > biggest->num ||
            (an[i].num == biggest->num && an[i].name < biggest->name))
            biggest = &an[i];
    }
    cout<<biggest->name<<" "<<biggest->num<<endl;
    return 0;
}