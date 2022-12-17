#include <cstring>
#include <iostream>
using namespace std;

class mystring {
   private:
    char* str_;
    int len_;

   public:
    mystring();
    mystring(const char*);
    mystring(const mystring&);
    ~mystring();
    mystring& operator=(const mystring&);
    friend istream& operator>>(istream&, mystring&);
    friend ostream& operator<<(ostream&, const mystring&);
};

class Stock {
   private:
    mystring company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }

   public:
    Stock();  // default constructor
    Stock(const mystring& co, long n = 0, double pr = 0.0);
    ~Stock();  // do-nothing destructor
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    friend ostream& operator<<(ostream&, const Stock&);
    const Stock& topval(const Stock& s) const;
};

mystring::mystring() {
    str_ = new char[10];
    strcpy(str_, "Unknown");
    len_ = strlen(str_);
}

mystring::mystring(const char* a) {
    len_ = strlen(a);
    str_ = new char[len_ + 1];
    strcpy(str_, a);
}

mystring::mystring(const mystring& a) {
    len_ = a.len_;
    str_ = new char[len_ + 1];
    strcpy(str_, a.str_);
}

mystring::~mystring() { delete[] str_; }

mystring& mystring::operator=(const mystring& a) {
    len_ = a.len_;
    delete[] str_;
    str_ = new char[len_ + 1];
    strcpy(str_, a.str_);
    return *this;
}

istream& operator>>(istream& input, mystring& a) {
    char name[100];
    input.get(name, 100);
    a = mystring(name);
    return input;
}

ostream& operator<<(ostream& output, const mystring& a) {
    output << a.str_;
    return output;
}

// constructors
Stock::Stock()  // default constructor
{
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const mystring& co, long n, double pr) {
    company = co;
    if (n < 0) {
        std::cout << "Number of shares can't be negative; " << company
                  << " shares set to 0.\n";
        shares = 0;
    } else
        shares = n;
    share_val = pr;
    set_tot();
}

// class destructor
Stock::~Stock()  // quiet class destructor
{}

// other methods
void Stock::buy(long num, double price) {
    if (num < 0) {
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
    using std::cout;
    if (num < 0) {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    } else if (num > shares) {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    share_val = price;
    set_tot();
}


ostream& operator<<(ostream& output, const Stock& st) {
    using std::ios_base;
    ios_base::fmtflags orig =
    output.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = output.precision(3);

    output << "Company: " << st.company << " Shares: " << st.shares << '\n';
    output << "Share Price: $" << st.share_val;
    // set format to #.##
    output.precision(2);
    output << " Total Worth: $" << st.total_val<<" ";

    // restore original format
    output.setf(orig, ios_base::floatfield);
    output.precision(prec);
    return output;
}

const Stock& Stock::topval(const Stock& s) const {
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}

const int STKS = 4;
int main() {
    {
        // create an array of initialized objects
        Stock stocks[STKS] = {Stock("NanoSmart", 12, 20.0),
                              Stock("Boffo Objects", 200, 2.0),
                              Stock("Monolithic Obelisks", 130, 3.25),
                              Stock("Fleep Enterprises", 60, 6.5)};

        std::cout << "Stock holdings:\n";
        int st;
        for (st = 0; st < STKS; st++) cout << stocks[st];
        // set pointer to first element
        const Stock* top = &stocks[0];
        for (st = 1; st < STKS; st++) top = &top->topval(stocks[st]);
        // now top points to the most valuable holding
        std::cout << "\n\nMost valuable holding:\n";
        cout << *top;
    }
    // std::cin.get();
    return 0;
}