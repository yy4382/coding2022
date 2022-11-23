#include <iostream>
using namespace std;
class bankacc {
   private:
    string name_;
    string num_;
    float balance_;

   public:
    bankacc(float a = 0) {
        name_ = "noname";
        num_ = "NaN";
        balance_ = a;
        cout << balance_ << endl;
    }
    void displayAll();
    void deposit(float a);
    void withdraw(float);
};

void bankacc::displayAll() {
    cout << name_ << " " << num_ << " " << balance_ << endl;
}

void bankacc::deposit(float a) {
    balance_ += a;
    cout << balance_ << endl;
}

void bankacc::withdraw(float a) {
    if (balance_ < a)
        cout << "no enough balance!" << endl;
    else {
        balance_ -= a;
        cout << balance_ << endl;
    }
}

int main() {
    float a;
    cin >> a;
    bankacc acc(a);
    cin >> a;
    acc.deposit(a);
    cin >> a;
    acc.withdraw(a);
    return 0;
}