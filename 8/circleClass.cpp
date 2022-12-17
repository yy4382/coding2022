#include <iostream>
using namespace std;
const double PI = 3.14;

class circle {
   private:
    double radius_, perimeter_, space_;

   public:
    circle(double radius = 0) {
        radius_ = radius;
        perimeter_ = 2 * PI * radius;
        space_ = PI * radius * radius;
    }
    circle(const circle &a) {
        radius_ = a.radius_;
        perimeter_ = a.perimeter_;
        space_ = a.space_;
    }
    void show();
};



void circle::show() {
    cout << radius_ << " " << perimeter_ << " " << space_ << endl;
}

int main() {
    double radius;
    cin >> radius;
    circle cir(radius);
    cir.show();
    return 0;
}