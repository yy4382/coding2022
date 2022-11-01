#include <iostream>
#include <iomanip>
using namespace std;
const int arsz = 3;

int main()
{
    string num[arsz] = {"10001", "10002", "10003"}, name[arsz] = {"Zhang", "Yang", "Liang"};
    int cls[arsz] = {11, 12, 11};
    double g1[arsz] = {99.5, 77.9, 92.5}, g2[arsz] = {88.5, 56.5, 99.0}, g3[arsz] = {89.5, 87.5, 60.5};
    bool isDelete[arsz] = {0};
    // initialization
    string input;
    cin >> input;
    for (int i = 0; i < arsz; i++)
    {
        if (input == num[i] || input == name[i])
            isDelete[i] = true;
    }
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
                input = num[j];
                num[j] = num[j + 1];
                num[j + 1] = input;

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

                ntemp = isDelete[j];
                isDelete[j] = isDelete[j + 1];
                isDelete[j + 1] = ntemp;

                input = name[j];
                name[j] = name[j + 1];
                name[j + 1] = input;
            }
        }
    }
    // sort
    for (int i = 0; i < arsz; i++)
    {
        if (!isDelete[i])
            cout << num[i] << " " << cls[i] << " " << name[i] << " " << fixed << setprecision(1) << g1[i] << " " << g2[i] << " " << g3[i] << endl;
    }
    if (!(isDelete[0] || isDelete[1] || isDelete[2]))
        return 0;
    cout << "Are you sure(yes/no)?" << endl;
    cin >> input;
    if (input == "n")
    {

        for (int i = 0; i < arsz; i++)
        {
            cout << num[i] << " " << cls[i] << " " << name[i] << " " << fixed << setprecision(1) << g1[i] << " " << g2[i] << " " << g3[i] << endl;
        }
    }
    // output
    return 0;
}