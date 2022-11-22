#include <iostream>
using namespace std;
class rectangle {
   private:
    float length;
    float width;

   public:
    void input();
    float perimeter();
    float space();
    float operator+(rectangle&);
    float operator*(rectangle&);
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

float rectangle::perimeter() { return 2 * length + 2 * width; }

float rectangle::space() { return length * width; }

float rectangle::operator+(rectangle& b) {
    return this->perimeter() + b.perimeter();
}

float rectangle::operator*(rectangle& b) { return this->space() + b.space(); }

int main() {
    rectangle rec1, rec2;
    rec1.input();
    rec2.input();
    cout << rec1 + rec2 << " " << rec1 * rec2 << endl;
    return 0;
}