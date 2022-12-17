#include <iostream>
using namespace std;

typedef unsigned long Item;

class Stack {
   private:
    enum { MAX = 10 };
    Item *pitems;
    int size;
    int top;

   public:
    Stack(int n = MAX);
    Stack(const Stack &st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &item);
    bool pop(Item &item);
    Stack &operator=(const Stack &st);
    friend ostream &operator<<(ostream &os, const Stack &st);
};

Stack::Stack(int n) {
    pitems = new Item[n];
    for (int i = 0; i < n; i++) {
        pitems[i] = 0;
    }
    top = 0;
    size = n;
}

Stack::Stack(const Stack &st) {
    pitems = new Item[st.size];
    for (int i = 0; i < st.size; i++) {
        pitems[i] = st.pitems[i];
    }
    top = st.top;
    size = st.size;
}

Stack::~Stack() { delete[] pitems; }

bool Stack::isempty() const { return top == 0; }

bool Stack::isfull() const { return top == MAX; }

bool Stack::push(const Item &item) {
    if (top < MAX) {
        pitems[top++] = item;
        return true;
    } else
        return false;
}

bool Stack::pop(Item &item) {
    if (top > 0) {
        item = pitems[--top];
        return true;
    } else
        return false;
}

Stack &Stack::operator=(const Stack &st) {
    if (this == &st) return *this;
    delete[] pitems;
    top = st.top;
    size = st.size;
    pitems = new Item[st.size];
    for (int i = 0; i < st.size; i++) {
        pitems[i] = st.pitems[i];
    }
    return *this;
}

ostream &operator<<(ostream &os, const Stack &st) {
    for (int i = 0; i < st.top; i++) {
        os << st.pitems[i] << endl;
    }
    return os;
}
// usestack.cpp -- tetsing the Stack class

int main() {
    using namespace std;
    Stack st;
    char ch;
    unsigned long po;
    cout << "Please enter A to add a purchase order.\n"
         << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q') {
        while (cin.get() != '\n') continue;
        if (!isalpha(ch)) {
            cout << '\a';
            continue;
        }
        switch (ch) {
            case 'A':
            case 'a':
                cout << "Enter a PO number to add:\n";
                cin >> po;
                if (st.isfull())
                    cout << "stack already full.\n";
                else
                    st.push(po);
                break;
            case 'p':
            case 'P':
                if (st.isempty())
                    cout << "stack already empty\n";
                else {
                    st.pop(po);
                    cout << "PO #" << po << " popped\n";
                }
                break;
        }
        cout << "Please enter A to add a purchase order.\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}