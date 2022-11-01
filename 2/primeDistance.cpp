#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int a)
{
    bool flag = 1;
    for (int i = 2; i <= sqrt(a); i++)
        if (a % i == 0)
        {
            flag = 0;
            break;
        }
    if (a <= 1)
        flag = 0;
    return flag;
}

int main()
{
    long long m, d1 = 0, d2 = 0;
    cin >> m;
    bool flag = 0, error = 0;
    if (m >= 2)
        while (!isPrime(m - d1))
            d1++;
    else
        error = 1;
    while (!isPrime(m + d2))
        d2++;
    if (d1 <= d2 && 0 == error)
        cout << m - d1 << " " << d1 << endl;
    else
        cout << m + d2 << " " << d2 << endl;
    return 0;
}