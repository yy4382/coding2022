#include <iomanip>
#include <iostream>
using namespace std;

struct stue {
    int num, cls;
    string name;
    double g1, g2, g3;
};
int main() {
    stue stu[7]{
        {10001, 11, "Zhang", 99.5, 88.5, 89.5},
        {10002, 12, "Yang", 77.9, 56.5, 87.5},
        {10003, 11, "Liang", 92.5, 99.0, 60.5},
        {10004, 11, "Cai", 93.6, 67.9, 90.5},
        {10005, 14, "Fu", 55.6, 67.9, 98.9},
        {10006, 12, "Mao", 22.1, 45.9, 99.2},
        {10007, 13, "Zhan", 35.6, 67.9, 88.0},
    };
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6 - i; j++) {
            double sortj = stu[j].cls * 1000000 -
                           (stu[j].g1 + stu[j].g2 + stu[j].g3) * 1000 -
                           stu[j].g1;
            double sortj1 =
                stu[j + 1].cls * 1000000 -
                (stu[j + 1].g1 + stu[j + 1].g2 + stu[j + 1].g3) * 1000 -
                stu[j + 1].g1;
            if (sortj > sortj1) {
                stue tmp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < 7; i++) {
        cout << stu[i].num << " " << stu[i].cls << " " << stu[i].name << " "
             << fixed << setprecision(1) << stu[i].g1 << " " << stu[i].g2 << " "
             << stu[i].g3 << " " << stu[i].g1 + stu[i].g2 + stu[i].g3 << endl;
    }
    return 0;
}