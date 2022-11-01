#include <iostream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    bool a[1005] = {0};
    for (int i = 1; i <= k; i++)
        for (int j = i; j <= n; j+=i) a[j] ^= 1;
    for (int i = 0; i <= n; i++)
        if (a[i]) cout << i << " ";
    cout << endl;
    return 0;
}