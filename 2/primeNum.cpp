#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int max = 1000;
    int su[max] = {0};
    for (int i = 0; i < max; i++) {
        bool flag = 1;
        for (int j = 2; j <= sqrt(i + 1); j++) {
            if ((i + 1) % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag)
            su[i] = 1;
    }
    int count = 0;
    for (int i = 1; i < max; i++) {
        if (su[i]) {
            cout << setw(5) << i + 1;
            count++;
        }
        if (count == 5) {
            cout << endl;
            count = 0;
        }
    }
}