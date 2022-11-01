#include <iostream>
using namespace std;
const int size = 10;

int search(const int a[], int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (a[mid] == target)
            return mid;
        else if (a[mid] < target)
            left = mid+1;
        else if (a[mid] > target)
            right = mid;
    }
    return -1;
}
int main() {
    int a[size], target;
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    cin >> target;
    cout << search(a, size, target) << endl;
    return 0;
}