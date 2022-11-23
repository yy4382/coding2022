#include <iostream>
using namespace std;

class Move {
   private:
    double x;
    double y;

   public:
    Move(double a = 0, double b = 0);  // sets x, y to a, b
    void showmove() const;             // shows current x, y values
    Move add(const Move& m) const;
    void reset(double a = 0, double b = 0);  // resets x,y to a, b
};

Move::Move(double a, double b) {
    x = a;
    y = b;
}
void Move::showmove() const { cout << x << "," << y << endl; }
Move Move::add(const Move& m) const {
    Move re;
    re.x = x + m.x;
    re.y = y + m.y;
    return re;
}

void Move::reset(double a, double b) {
    x = a;
    y = b;
}  // resets x,y to a, b

int main() {
    Move a;
    a.showmove();
    double x1, y1;
    cin >> x1;
    cin.get();
    cin >> y1;
    Move b(x1, y1);
    b.showmove();
    a = a.add(b);
    a.showmove();
    b.reset();
    b.showmove();
    return 0;
}