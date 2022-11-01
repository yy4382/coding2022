#include <cstring>
#include <iostream>
using namespace std;

char* toupper(char str[], int n) {
    for (int i = 0; i < n; i++)
        if (str[i] >= 'a' && str[i] <= 'z') str[i] = int(str[i] - 32);
    return str;
}

int main() {
    char str[1000];
    cin.getline(str,1000);
    int n = strlen(str);
    cout << toupper(str, n) << endl;
    return 0;
}