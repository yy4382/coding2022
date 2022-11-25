#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
bool ifquit = 0;

class complex {
   private:
    double real_;
    double ima_;

   public:
    complex(double = 0, double = 0);
    complex operator+(const complex) const;
    complex operator-(const complex) const;
    complex operator*(const complex) const;
    friend istream &operator>>(istream &, complex &);
    friend ostream &operator<<(ostream &, const complex);
    friend complex operator*(const double, const complex);
    friend complex operator~(const complex);
};

complex::complex(double a, double b) {
    real_ = a;
    ima_ = b;
}
complex complex::operator+(const complex a) const {
    complex re(real_ + a.real_, ima_ + a.ima_);
    return re;
}
complex complex::operator-(const complex a) const {
    complex re(real_ - a.real_, ima_ - a.ima_);
    return re;
}
complex complex::operator*(const complex a) const {
    complex re(real_ * a.real_ - ima_ * a.ima_,
               real_ * a.ima_ + ima_ * a.real_);
    return re;
}
complex operator*(const double x, const complex a) {
    complex re(x * a.real_, x * a.ima_);
    return re;
}
complex operator~(const complex a) {
    complex re(a.real_, -a.ima_);
    return re;
}
istream &operator>>(istream &cinn, complex &a) {
    cout << "real:";
    cinn >> a.real_;
    if (cinn) {
        cout << "imaginary:";
        cinn >> a.ima_;
    }
    return cinn;
}
ostream &operator<<(ostream &coutt, const complex a) {
    coutt << "(" << a.real_ << "," << a.ima_ << "i)";
    return coutt;
}

int main() {
    complex a(3.0, 4.0);  // initialize to (3,4i)
    complex c;
    cout << "Enter a complex number (q to quit):\n";
    while (cin >> c) {
        cout << "c is " << c << '\n';
        cout << "complex conjugate is " << ~c << '\n';
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "2 * c is " << 2 * c << '\n';
        cout << "Enter a complex number (q to quit):\n";
    }
    cout << "Done!\n";
    return 0;
}