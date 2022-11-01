#include <iostream>
#include <iomanip>
using namespace std;
const int arsz = 3;

int main()
{
    string num[arsz] = {"10001", "10002", "10003"}, name[arsz] = {"Zhang", "Yang", "Liang"};
    int cls[arsz] = {11, 12, 11};
    double g1[arsz] = {99.5, 77.9, 92.5}, g2[arsz] = {88.5, 56.5, 99.0}, g3[arsz] = {89.5, 87.5, 60.5};
    bool isModified[arsz] = {0};
    // initialization
    string numIn, nameIn;
    int clsIn;
    double g1In, g2In, g3In;
    cin >> numIn >> clsIn >> nameIn >> g1In >> g2In >> g3In;
    for (int i = 0; i < arsz; i++)
    {
        if (numIn == num[i])
        {
            cls[i] = clsIn;
            name[i] = nameIn;
            g1[i] = g1In;
            g2[i] = g2In;
            g3[i] = g3In;
            isModified[i] = true;
        }
    }
    // input
    double sort[arsz], ftemp;
    int ntemp;
    string temp;
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
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;

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

                ntemp = isModified[j];
                isModified[j] = isModified[j + 1];
                isModified[j + 1] = ntemp;

                temp = name[j];
                name[j] = name[j + 1];
                name[j + 1] = temp;
            }
        }
    }
    // sort
    int clsc = -1;
    for (int i = 0; i < arsz; i++)
    {
        if (clsc != cls[i])
            cout << cls[i] << " ";
        else
            cout << "   ";
        cout << num[i] << " " << name[i] << " " << fixed << setprecision(1) << g1[i] << " " << g2[i] << " " << g3[i];
        if (isModified[i])
            cout << " modified";
        cout << endl;
        clsc=cls[i];
    }
    // output
    return 0;
}