#include <iostream>
using namespace std;
class rectangle {
   private:
    float length;
    float width;

   public:
    void input();
    void perimeter();
    void space();
};

void rectangle::input() {
    float x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 < x2) {
        length = x2 - x1;
    } else {
        length = x1 - x2;
    }
    if (y1 < y2) {
        width = y2 - y1;
    } else {
        width = y1 - y2;
    }
}

void rectangle::perimeter() { cout << 2 * length + 2 * width << " "; }

void rectangle::space() { cout << length * width << endl; }

int main() {
    rectangle rec;
    rec.input();
    rec.perimeter();
    rec.space();
    return 0;
}