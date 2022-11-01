#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        bool flag = true;
        for (int j = 2; j <= sqrt(a[i]); j++)
            if (a[i] % j == 0)
            {
                flag = 0;
                break;
            }
        if (flag && a[i] != 1)
            sum += a[i];
    }
    cout << sum << endl;
    return 0;
}