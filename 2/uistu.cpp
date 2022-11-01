#include <iostream>
#include <iomanip>
using namespace std;

struct stu
{
    string num;
    float a, b, c, sum, avg;
};

int main()
{
    char input;
    cout << "                              1.Input\n                              2.Output\n                              3.Order\n                              4.Quit\n";
    cin >> input;
    stu stue[3], temp;
    switch (int(input))
    {
    case 105:
        cout << "Please input info of the three students:\n";
        for (int i = 0; i < 3; i++)
        {
            cin >> stue[i].num >> stue[i].a >> stue[i].b >> stue[i].c;
            stue[i].sum = stue[i].a + stue[i].b + stue[i].c;
            stue[i].avg = stue[i].sum / 3;
        }
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
        for (int i = 0; i < 3; i++)
        {
            cout << stue[i].num << fixed << setprecision(1) << "," << stue[i].sum << "," << stue[i].avg << endl;
        }
        break;
    case 111:
        cout << "You are trying to Output info\n";
        break;
    case 109:
        cout << "You are trying to Make things ordered\n";
        break;
    case 113:
        cout << "You are about to Quit\n";
        break;
    default:
        cout << "Wrong input\n";
        break;
    }
    return 0;
}