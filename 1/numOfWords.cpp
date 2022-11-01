#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[20];
    int word = 0;
    while (strcmp(a, "done") != 0)
    {
        cin >> a;
        word++;
    }
    cout <<"You entered a total of " << word - 1 << " words."<< endl;
    return 0;
}