#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[256], ans;
    cin.getline(str, 256);
    cin >> ans;
    int count = 0;
    bool flag = 1;
    for (int i = 0; *(str + i) != 0; i++)
    {
        count++;
        flag=(*(str+i) ==int(ans));
        if (flag)
            break;
    }
    if (flag)
        cout << count << endl;
    else
        cout << 0 << endl;
    return 0;
}