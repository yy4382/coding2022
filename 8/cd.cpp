#include <cstring>
#include <iostream>
using namespace std;

class Cd {
   private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;

   public:
    Cd(const char* s1, const char* s2, int n, double x);
    // Cd(const Cd& d);
    Cd(){};
    virtual ~Cd() {}
    virtual void Report() const;
    //Cd& operator=(const Cd& d);
};

class Classic : public Cd {
   private:
    char content[100];

   public:
    Classic() {}
    Classic(const char* s0, const char* s1, const char* s2, int n, double x) : Cd(s1, s2, n, x) {
        strcpy(content, s0);
    }
    virtual void Report() const;
    virtual ~Classic() {}
};

void Bravo(const Cd& disk);

int main() {
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 =
        Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
    Cd* pcd = &c1;
    cout << "Using object directly:\n";
    c1.Report();
    c2.Report();
    cout << "Using type cd * pointer to objects:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << "Testing assignment: ";  // 注意此处冒号后有一个空格
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}

void Bravo(const Cd& disk) { disk.Report(); }

Cd::Cd(const char* s1, const char* s2, int n, double x) {
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

void Cd::Report() const {
    cout << performers << "," << label << "," << selections << "," << playtime << endl;
}

void Classic::Report() const {
    cout<<content<<",";
    this->Cd::Report();
}