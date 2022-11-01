#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 1 || n == 2)
        return 1;
    else {
        int a = fibonacci(n - 1) + fibonacci(n - 2);
        return a;
    }
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
