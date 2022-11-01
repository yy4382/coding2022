#include <iomanip>
#include <iostream>
using namespace std;

struct stu
{
    int num, cls;
    double g1, g2, g3, sum;
};

int main()
{
    stu stue[3], temp;
    for (int i = 0; i < 3; i++)
    {
        cin >> stue[i].num >> stue[i].cls >> stue[i].g1 >> stue[i].g2 >> stue[i].g3;
        stue[i].sum = stue[i].g1 + stue[i].g2 + stue[i].g3;
    }
    // input and caculate sum
    if (stue[0].sum > stue[1].sum)
    {
        temp = stue[0];
        stue[0] = stue[1];
        stue[1] = temp;
    }
    if (stue[1].sum > stue[2].sum)
    {
        temp = stue[1];
        stue[1] = stue[2];
        stue[2] = temp;
    }
    if (stue[0].sum > stue[1].sum)
    {
        temp = stue[0];
        stue[0] = stue[1];
        stue[1] = temp;
    }
    // sort
    if (stue[0].cls == stue[1].cls && stue[1].cls == stue[2].cls)
    {
        cout << stue[0].cls << ",";
        for (int i = 0; i < 2; i++)
            cout << stue[i].num << "," << fixed << setprecision(1) << stue[i].sum << ";";
        cout << stue[2].num << "," << fixed << setprecision(1) << stue[2].sum;
    }
    // case 1: 3 in 1 class
    else if (stue[0].cls == stue[1].cls && stue[1].cls > stue[2].cls)
    {
        cout << stue[0].cls << "," << stue[0].num << "," << fixed << setprecision(1) << stue[0].sum << ";";
        cout << stue[1].num << "," << fixed << setprecision(1) << stue[1].sum << endl;
        ;
        cout << stue[2].cls << "," << stue[2].num << "," << fixed << setprecision(1) << stue[2].sum << endl;
    }
    else if (stue[0].cls == stue[1].cls && stue[1].cls < stue[2].cls)
    {
        cout << stue[2].cls << "," << stue[2].num << "," << fixed << setprecision(1) << stue[2].sum << endl;
        cout << stue[0].cls << "," << stue[0].num << "," << fixed << setprecision(1) << stue[0].sum << ";";
        cout << stue[1].num << "," << fixed << setprecision(1) << stue[1].sum << endl;
    }
    // case2.1: 0 and 1 together
    else if (stue[0].cls == stue[2].cls && stue[2].cls > stue[1].cls)
    {
        cout << stue[0].cls << "," << stue[0].num << "," << fixed << setprecision(1) << stue[0].sum << ";";
        cout << stue[2].num << "," << fixed << setprecision(1) << stue[2].sum << endl;
        cout << stue[1].cls << "," << stue[1].num << "," << fixed << setprecision(1) << stue[1].sum << endl;
    }
    else if (stue[0].cls == stue[2].cls && stue[2].cls < stue[1].cls)
    {
        cout << stue[1].cls << "," << stue[1].num << "," << fixed << setprecision(1) << stue[1].sum << endl;
        cout << stue[0].cls << "," << stue[0].num << "," << fixed << setprecision(1) << stue[0].sum << ";";
        cout << stue[2].num << "," << fixed << setprecision(1) << stue[2].sum << endl;
    }
    // case2.2: 0 and 2 together
    else if (stue[1].cls == stue[2].cls && stue[2].cls > stue[0].cls)
    {
        cout << stue[1].cls << "," << stue[1].num << "," << fixed << setprecision(1) << stue[1].sum << ";";
        cout << stue[2].num << "," << fixed << setprecision(1) << stue[2].sum << endl;
        cout << stue[0].cls << "," << stue[0].num << "," << fixed << setprecision(1) << stue[0].sum << endl;
    }
    else if (stue[1].cls == stue[2].cls && stue[2].cls < stue[0].cls)
    {
        cout << stue[0].cls << "," << stue[0].num << "," << fixed << setprecision(1) << stue[0].sum << endl;
        cout << stue[1].cls << "," << stue[1].num << "," << fixed << setprecision(1) << stue[1].sum << ";";
        cout << stue[2].num << "," << fixed << setprecision(1) << stue[2].sum << endl;
    }
    // case2.3: 1 and 2 together
    else
    {
        if (stue[0].cls < stue[1].cls)
        {
            temp = stue[0];
            stue[0] = stue[1];
            stue[1] = temp;
        }
        if (stue[1].cls < stue[2].cls)
        {
            temp = stue[1];
            stue[1] = stue[2];
            stue[2] = temp;
        }
        if (stue[0].cls < stue[1].cls)
        {
            temp = stue[0];
            stue[0] = stue[1];
            stue[1] = temp;
        }
        for (int i = 0; i < 3; i++)
            cout << stue[i].cls << "," << stue[i].num << "," << fixed << setprecision(1) << stue[i].sum << endl;
    }
    // case 3: all different
    return 0;
}