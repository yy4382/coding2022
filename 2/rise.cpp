#include <iostream>
using namespace std;
const int size = 10;

int main()
{
    float a[size];
    for (int i = 0; i < size; i++)
        cin >> a[i];
    float temp;
    bool exchange = false;
    for (int i = 0; i < size - 1; i++)
    {
        exchange = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if(a[j]>a[j+1])
           {
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            exchange = 1;
           }
        }
        if (!exchange)
            break;
    }

    for (int i = 0; i < size; i++)
    {
        cout << a[i];
        if (i == 9)
            cout << endl;
        else
            cout << " ";
    }
    return 0;
}