#include <iostream>
using namespace std;

class Point {
    friend int calcH(const Point&, const Point&);
    friend int calcV(const Point&, const Point&);

   private:
    int x, y;

   public:
    Point(int i = 0, int j = 0) { 
        cin >> i >> j;
        x=i;
        y=j;
    }
};

int calcH(const Point& a, const Point& b) {
    int re = a.x - b.x;
    if (re < 0)
        return -re;
    else
        return re;
}

int calcV(const Point& a, const Point& b) {
    int re = a.y - b.y;
    if (re < 0)
        return -re;
    else
        return re;
}

int main() {
    Point a, b;
    cout << calcH(a, b) << " " << calcV(a, b) << endl;
    return 0;
}