#include <cstring>
#include <iostream>
using namespace std;
class person {
   private:
    char Idperson[20], Name[20], Sex[20], Birth[20], Homeaddr[20];

   public:
    person(const char*, const char*, const char*, const char*, const char*);
    person(const person&);
    person();
    friend ostream& operator<<(ostream&, const person&);
    friend istream& operator>>(istream&, person&);
};

person::person(const char a[], const char b[], const char c[], const char d[],
               const char e[]) {
    strcpy(Idperson, a);
    strcpy(Name, b);
    strcpy(Sex, c);
    strcpy(Birth, d);
    strcpy(Homeaddr, e);
}
person::person() {
    strcpy(Idperson, "Unknown");
    strcpy(Name, "Unknown");
    strcpy(Sex, "Unknown");
    strcpy(Birth, "Unknown");
    strcpy(Homeaddr, "Unknown");
}
person::person(const person& a) {
    strcpy(Idperson, a.Idperson);
    strcpy(Name, a.Name);
    strcpy(Sex, a.Sex);
    strcpy(Birth, a.Birth);
    strcpy(Homeaddr, a.Homeaddr);
}

ostream& operator<<(ostream& output, const person& a){
    output<<a.Idperson<<" "<<a.Name<<" "<<a.Sex<< " "<<a.Birth<<" "<<a.Homeaddr<<endl;
    return output;
}
istream& operator>>(istream&input, person&a){
    input>>a.Idperson>>a.Name>>a.Sex>>a.Birth>>a.Homeaddr;
    return input;
}
int main(){
    person sb;
    cin>>sb;
    cout<<sb;
    return 0;
}