#include <iostream>
using namespace std;

int main()
{
    long long a[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> a[i];
    }
    for (int i = 7; i > -1; i--)
    {
        cout << a[i];
        if (i != 0)
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}