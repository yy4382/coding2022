#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

const int SIZE = 15;
struct stu {
    int Id, cls;
    char name[10];
    float s1, s2, s3;
    bool beselected;
};
stu stue[SIZE];

void input(stu *stue);
void set_select_true(stu *stue);
void output(stu *stue);
void del(stu *stue);
void select(stu *stue);
void order(stu *stue);

int main() {
    char menu[256] =
        "1.input\n2.delete\n3.select\n4.order\n5.output\n6.quit\nplease input "
        "your option\n";
    int cata;
    for (int i = 0; i < SIZE; i++) {
        stue[i].beselected = 1;
        stue[i].Id = -1;
    }
    while (1) {
        cout << menu;
        cin >> cata;
        switch (cata) {
            case 1:
                input(stue);
                break;
            case 2:
                del(stue);
                break;
            case 3:
                select(stue);
                break;
            case 4:
                order(stue);
                break;
            case 5:
                output(stue);
                break;
            case 6:
                return 0;
        }
    }
}

void input(stu *stue) {
    int i = 0;
    while (stue[i].Id != -1) {
        i++;
    }
    cout << "Id ";
    cin >> stue[i].Id;
    cout << "class ";
    cin >> stue[i].cls;
    cout << "name ";
    cin >> stue[i].name;
    cout << "score1 ";
    cin >> stue[i].s1;
    cout << "score2 ";
    cin >> stue[i].s2;
    cout << "score3 ";
    cin >> stue[i].s3;
    cout << "continue?\n";
    char in[5];
    cin >> in;
    if (!strcmp(in, "yes")) input(stue);
    if (!strcmp(in, "no")) return;
}

void del(stu *stue) {
    int nin = -1;
    char chin[10]{'\0'};
    cin >> nin;
    if (cin)
        for (int i = 0; i < SIZE; i++) {
            if (stue[i].Id != -1 && nin == stue[i].Id) stue[i].Id = -1;
        }
    else {
        cin.clear();
        cin >> chin;
        for (int i = 0; i < SIZE; i++) {
            if (stue[i].Id != -1 && !strcmp(chin, stue[i].name))
                stue[i].Id = -1;
        }
    }
    set_select_true(stue);
    output(stue);
    cout << "continue?\n";
    char in[5];
    cin >> in;
    if (!strcmp(in, "yes")) del(stue);
    if (!strcmp(in, "no")) return;
}

void select(stu *stue) {
    int in = 0;
    cin >> in;
    for (int i = 0; i < SIZE; i++) {
        stue[i].beselected = 0;
        if (stue[i].cls == in || stue[i].Id == in) stue[i].beselected = 1;
    }
    output(stue);
    cout << "continue?\n";
    char inp[5];
    cin >> inp;
    if (!strcmp(inp, "yes")) select(stue);
    if (!strcmp(inp, "no")) return;
}

void order(stu *stue) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (float(stue[j].cls * 1000) - stue[j].s1 - stue[j].s2 -
                    stue[j].s3 >
                float(stue[j + 1].cls * 1000) - stue[j + 1].s1 -
                    stue[j + 1].s2 - stue[j + 1].s3) {
                stu temp = stue[j];
                stue[j] = stue[j + 1];
                stue[j + 1] = temp;
            }
        }
    }
    set_select_true(stue);
    output(stue);
}

void output(stu *stue) {
    for (int i = 0; i < SIZE; i++) {
        if (stue[i].Id != -1 && stue[i].beselected) {
            cout << stue[i].Id << "," << stue[i].cls << "," << stue[i].name
                 << "," << fixed << setprecision(1) << stue[i].s1 << ","
                 << stue[i].s2 << "," << stue[i].s3 << ","
                 << stue[i].s1 + stue[i].s2 + stue[i].s3 << "\n";
        }
    }
}

void set_select_true(stu *stue) {
    for (int i = 0; i < SIZE; i++) stue[i].beselected = 1;
}