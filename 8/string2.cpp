#include <cstring>
#include <iostream>
using namespace std;

class String {
   private:
    char *str;                     // pointer to string
    int len;                       // length of string
    static int num_strings;        // number of objects
    static const int CINLIM = 80;  // cin input limit
   public:
    // constructors and other methods
    String(const char *s);   // constructor
    String();                // default constructor
    String(const String &);  // copy constructor
    ~String();               // destructor
    int length() const { return len; }
    // overloaded operator methods
    String &operator=(const String &);
    String &operator=(const char *);
    char &operator[](int i);
    const char &operator[](int i) const;
    void stringlow();
    void stringup();
    int has(const char target);
    // overloaded operator friends
    friend bool operator<(const String &st, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st, const String &st2);
    friend String operator+(const String &st1, const String &st2);
    friend String operator+(const char *st1, const String &st2);
    friend String operator+(const String &st1, const char *st2);
    friend ostream &operator<<(ostream &os, const String &st);
    friend istream &operator>>(istream &is, String &st);
    // static function
    static int HowMany();
};
int String::num_strings = 0;

int main() {
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name:\n";
    String s3;
    cout << s2;               // overloaded << operator
    cin >> s3;                // overloaded >> operator
    s2 = "My name is " + s3;  // overloaded =, + operators
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup();  // converts string to uppercase
    cout << "The string " << s2 << "\ncontains " << s2.has('A')
         << " 'A' characters in it.\n";
    s1 = "red";  // String(const char *),
    // then String & operator=(const String&)
    String rgb[3] = {String(s1), String("green"), String("blue")};
    cout << "Enter the name of a primary color for mixing light:\n";
    String ans;
    bool success = false;
    while (cin >> ans) {
        ans.stringlow();  // converts string to lowercase
        for (int i = 0; i < 3; i++) {
            if (ans == rgb[i])  // overloaded == operator
            {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again!\n";
    }
    cout << "Bye\n";
    return 0;
}

// static method
int String::HowMany() { return num_strings; }

// class methods
String::String(const char *s)  // construct String from C string
{
    len = std::strlen(s);     // set size
    str = new char[len + 1];  // allot storage
    std::strcpy(str, s);      // initialize pointer
    num_strings++;            // set object count
}

String::String()  // default constructor
{
    len = 4;
    str = new char[1];
    str[0] = '\0';  // default string
    num_strings++;
}

String::String(const String &st) {
    num_strings++;             // handle static member update
    len = st.len;              // same length
    str = new char[len + 1];   // allot space
    std::strcpy(str, st.str);  // copy string to new location
}

String::~String()  // necessary destructor
{
    --num_strings;  // required
    delete[] str;   // required
}

// overloaded operator methods

// assign a String to a String
String &String::operator=(const String &st) {
    if (this == &st) return *this;
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

// assign a C string to a String
String &String::operator=(const char *s) {
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

// read-write char access for non-const String
char &String::operator[](int i) { return str[i]; }

// read-only char access for const String
const char &String::operator[](int i) const { return str[i]; }

// overloaded operator friends

bool operator<(const String &st1, const String &st2) {
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2) { return st2 < st1; }

bool operator==(const String &st1, const String &st2) {
    return (std::strcmp(st1.str, st2.str) == 0);
}

// simple String output
ostream &operator<<(ostream &os, const String &st) {
    os << st.str;
    return os;
}

// quick and dirty String input
istream &operator>>(istream &is, String &st) {
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is) st = temp;
    while (is && is.get() != '\n') continue;
    return is;
}

String operator+(const String &st1, const String &st2) {
    int length = st1.len + st2.len;
    char rech[length + 1];
    strcpy(rech, st1.str);
    for (int i = st1.len; i <= length; i++) rech[i] = st2.str[i - st1.len];
    String restr(rech);
    return restr;
}
String operator+(const char *st1, const String &st2) {
    int len1 = strlen(st1);
    char rech[len1 + st2.len];
    strcpy(rech, st1);
    for (int i = 0; i <= st2.len; i++) rech[i + len1] = st2.str[i];
    String restr(rech);
    return restr;
}
String operator+(const String &st1, const char *st2) {
    int len2 = strlen(st2);
    char rech[st1.len + len2];
    strcpy(rech, st1.str);
    for (int i = 0; i <= len2; i++) rech[i + st1.len] = st2[i];
    String restr(rech);
    return restr;
}

void String::stringlow() {
    for (int i = 0; i < len; i++)
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] + 32;
}
void String::stringup() {
    for (int i = 0; i < len; i++)
        if (str[i] >= 'a' && str[i] <= 'z') str[i] = str[i] - 32;
}
int String::has(const char target) {
    int cnt = 0;
    for (int i = 0; i < len; i++)
        if (str[i] == target) cnt++;
    return cnt;
}