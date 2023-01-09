#include <iostream>
#include <valarray>
using namespace std;


template <typename T1, typename T2>
class Pair {
   private:
    T1 a;
    T2 b;

   public:
    T1 &first() { return a; }
    T2 &second() { return b; }
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair(const T1 &aval, const T2 &bval) : a(aval), b(bval) {}
    Pair(){}
};

typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine {
   private:
    string label;
    PairArray data;

   public:
    Wine() {}
    Wine(const char *l, int y, const int yr[], const int bot[])
        : label(l), data(PairArray(ArrayInt(yr, y), ArrayInt(bot, y))) {}
    Wine(const char *l, int y) : label(l), data(PairArray(ArrayInt(y), ArrayInt(y))) {}
    void GetBottles();
    void Show();
    string &Label() { return label; };
    int sum();
};

void Wine::GetBottles() {
    int y = data.first().size();
    ArrayInt year(y), bottle(y);

    cout << "Enter " << label << " data for " << y << " year(s): \n";
    for (int i = 0; i < y; i++) {
        cout << "Enter year: \n";
        cin >> year[i];
        cout << "Enter bottles for that year: \n";
        cin >> bottle[i];
    }
    data = PairArray(year, bottle);
}

void Wine::Show() {
    cout << "Wine: " << label << "\n        Year    Bottles\n";
    for (int i = 0; i < data.first().size(); i++)
        cout << "        " << data.first()[i] << "    " << data.second()[i] << endl;
}

int Wine::sum() {
    int sum = 0;
    for (int i = 0; i < data.first().size(); i++) sum += (data.second())[i];
    return sum;
}

int main(){
    cout<<"Enter name of wine: \n";
    char lab[50];
    cin.getline(lab,50);
    cout<<"Enter number of years: \n";
    int yrs;
    cin>>yrs;

    Wine holding(lab,yrs);
    holding.GetBottles();
    holding.Show();

    const int YRS=3;
    int y[YRS]={1993,1995,1998};
    int b[YRS]={48,60,72};
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    cout<<"Total bottles for "<<more.Label()<<": "<<more.sum()<<endl;
    cout<<"Bye\n";
    return 0;
}