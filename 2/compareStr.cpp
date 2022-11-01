#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char dst[256], src[256];
    int count = 0, flag = 0;
    cin.getline(dst, 256);
    cin.getline(src, 256);
    while (*(dst + count) == *(src + count))
    {
        if (*(dst + count) == 0 && 0 == *(src + count))
        {
            flag = 1;
            break;
        }
        count++;
    }
    if (flag)
        cout << 0 << endl;
    else
        cout << count + 1 << endl;
    return 0;
}