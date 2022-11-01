#include <iostream>
#include <iomanip>
using namespace std;
const int arsz = 4;

int main()
{
    int num[arsz] = {10001, 10002, 10003}, cls[arsz] = {11, 12, 11};
    double g1[arsz] = {99.5, 77.9, 92.5}, g2[arsz] = {88.5, 56.5, 99.0}, g3[arsz] = {89.5, 87.5, 60.5};
    bool isInsert[4] = {0, 0, 0, 1};
    // initialization
    cin >> num[3] >> cls[3] >> g1[3] >> g2[3] >> g3[3];
    if (num[3] == 10001 || num[3] == 10002 || num[3] == 10003)
        num[3] = 10000;
    // input
    double sort[arsz], ftemp;
    int ntemp;
    for (int i = 0; i < arsz; i++)
    {
        sort[i] = cls[i] * 10000 - g1[i] - g2[i] - g3[i];
    }
    for (int i = 0; i < arsz - 1; i++)
    {
        for (int j = 0; j < arsz - 1 - i; j++)
        {
            if (sort[j] > sort[j + 1])
            {
                ntemp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = ntemp;

                ntemp = cls[j];
                cls[j] = cls[j + 1];
                cls[j + 1] = ntemp;

                ftemp = g1[j];
                g1[j] = g1[j + 1];
                g1[j + 1] = ftemp;

                ftemp = g3[j];
                g3[j] = g3[j + 1];
                g3[j + 1] = ftemp;

                ftemp = g2[j];
                g2[j] = g2[j + 1];
                g2[j + 1] = ftemp;

                ftemp = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = ftemp;

                ntemp = isInsert[j];
                isInsert[j] = isInsert[j + 1];
                isInsert[j + 1] = ntemp;
            }
        }
    }
    // sort
    for (int i = 0; i < arsz; i++)
    {
        cout << num[i] << " " << cls[i] << " " << fixed << setprecision(1) << g1[i] << " " << g2[i] << " " << g3[i];
        if (isInsert[i])
            cout << " inserted";
        cout << endl;
    }
    // output
    return 0;
}