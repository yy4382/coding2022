#include <cstring>
#include <iostream>
using namespace std;

class Cd {
   private:
    char* performers;
    char* label;
    int selections;
    double playtime;

   public:
    Cd(const char* s1, const char* s2, int n, double x);
    // Cd(const Cd& d);
    Cd():selections(0),playtime(0){
        performers=new char[1];
        label=new char[1];
    }
    virtual ~Cd() { delete []performers, label; }
    virtual void Report() const;
    virtual Cd& operator=(const Cd& d){
        if(this == &d) return *this;
        delete [] performers,label;
        performers = new char [strlen(d.performers)+1];
        label = new char [strlen(d.label)+1];
        strcpy(label,d.label);
        strcpy(performers,d.performers);
        selections=d.selections;
        playtime=d.playtime;
        return *this;
    }
};

class Classic : public Cd {
   private:
    char* content;

   public:
    Classic():Cd() {content=new char [1];}
    Classic(const char* s0, const char* s1, const char* s2, int n, double x) : Cd(s1, s2, n, x) {
        int len = strlen(s0);
        content = new char[len + 1];
        strcpy(content, s0);
    }
    virtual void Report() const;
    virtual ~Classic() { delete [] content; };
    virtual Classic& operator=(const Classic& d){
        if(this == &d) return *this;
        Cd::operator=(d);
        delete [] content;
        content = new char [strlen(d.content)+1];
        strcpy(content,d.content);
        return *this;
    }
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
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    performers = new char[len1 + 1];
    label = new char[len2 + 1];
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

void Cd::Report() const {
    cout << performers << "," << label << "," << selections << "," << playtime << endl;
}

void Classic::Report() const {
    cout << content << ",";
    this->Cd::Report();
}