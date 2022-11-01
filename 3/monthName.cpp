#include <cstring>
#include <iostream>
using namespace std;
int main() {
    char name[12][20]{"January",   "February", "March",    "April",
                      "May",       "June",     "July",     "August",
                      "September", "October",  "November", "December"};
    char(*p)[20] = name;
    int in;
    cin >> in;
    cout << *(p + in - 1) << endl;
    return 0;
}