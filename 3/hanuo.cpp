#include <iostream>
using namespace std;
int hanuo(int n) {
    if(n==1) return 1;
    int result = (2 * hanuo(n - 1) + 1)%1000000;
    return result;
}

int main() {
    int m;
    cin >> m;
    cout << hanuo(m) << endl;
    return 0;
}