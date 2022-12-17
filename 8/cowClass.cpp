#include <cstring>
#include <iostream>
using namespace std;
class Cow {
    char name[20];
    char* hobby;
    double weight;

   public:
    Cow();
    Cow(const char* nm, const char* ho, double wt);
    Cow(const Cow&);
    ~Cow();
    Cow& operator=(const Cow& c);
    void ShowCow() const;  // display all cow data
};
int main() {
    char nm[20], ho[100];
    double wt;
    cin >> nm;
    cin.get();
    cin.getline(ho, 100);
    cin >> wt;
    Cow c1(nm, ho, wt);
    cin >> nm;
    cin.get();
    cin.getline(ho, 100);
    cin >> wt;
    Cow c2(nm, ho, wt);
    Cow c3 = c1;
    Cow c4;
    c4 = c2;
    c3.ShowCow();
    c4.ShowCow();
    return 0;
}

void Cow::ShowCow() const {
    cout << name << " " << hobby << " " << weight << endl;
}

Cow::Cow() {
    strcpy(name, "Unknown");
    hobby = new char[10];
    strcpy(hobby, "Unkown");
    weight = 0.0;
}
Cow::Cow(const char* nm, const char* ho, double wt) {
    strcpy(name, nm);
    int length = strlen(ho);
    hobby = new char[length + 1];
    strcpy(hobby, ho);
    weight = wt;
}
Cow::~Cow() { delete[] hobby; }
Cow::Cow(const Cow& c) {
    strcpy(name, c.name);
    int len = strlen(c.hobby);
    hobby = new char[len + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}
Cow& Cow::operator=(const Cow& c) {
    if (this == &c) return *this;
    strcpy(name, c.name);
    delete[] hobby;
    int len = strlen(c.hobby);
    hobby = new char[len + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}