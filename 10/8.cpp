#include <cmath>
#include <iostream>
using namespace std;

class largeInt {
    friend largeInt operator+(largeInt,largeInt);
    friend istream& operator>>(istream&, largeInt&);
    friend ostream& operator<<(ostream&, const largeInt&);

   private:
    string num_;

   public:
    largeInt(string a = "0");
};

largeInt::largeInt(string a) { num_ = a; }

largeInt operator+(largeInt a, largeInt b) {
    int len1 = a.num_.length();
    int len2 = b.num_.length();
    if (len1 < len2)
        for (int i = 0; i < len2 - len1; i++) a.num_ = "0" + a.num_;
    else
        for (int i = 0; i < len1 - len2; i++) b.num_ = "0" + b.num_;
    int ifadd = 0;
    len1 = a.num_.length();
    string res;
    for (int i = len1 - 1; i >= 0; i--) {
        int sumtmp = a.num_[i] + b.num_[i] - 96 + ifadd;
        res = char(sumtmp % 10 + 48) + res;
        ifadd = sumtmp / 10;
    }
    if (ifadd) res = "1" + res;
    largeInt result(res);
    return result;
}

istream& operator>>(istream& input, largeInt &a) {
    input >> a.num_;
    return input;
}

ostream& operator<<(ostream& output, const largeInt &a) {
    output << a.num_;
    return output;
}

int main(int argc, const char* argv[]) {
    // insert code here...
    largeInt int1, int2;
    std::cin >> int1;
    std::cin >> int2;
    std::cout << int1 + int2 << std::endl;
    return 0;
}