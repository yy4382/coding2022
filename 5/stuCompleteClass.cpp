#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
const int MAXSTU = 5;

class stud {
   private:
    int id, cls;
    string name;
    double grade[3], total;
    bool isUsing;     // 分别为有数据（未被删除）
    bool isSelected;  // 是否被选中

   public:
    stud() : id(0), cls(0), name("\0"), grade{}, total(0), isUsing(0), isSelected(0) {}
    void setTotalGrade() { total = grade[0] + grade[1] + grade[2]; }
    bool input();
    void del(int search) {
        if (isUsing && search == id) isUsing = 0;
    }
    void del(string search) {
        if (isUsing && search == name) isUsing = 0;
    }
    bool getIsSelected() { return isSelected; }
    void setIsSelected() { isSelected = 0; }
    bool match(int select);
    bool operator>(const stud&);
    friend ostream& operator>>(ostream& output, const stud& stu);
};

class grade {
   private:
    stud stu[MAXSTU];

   public:
    void input();
    void del();
    void select();
    void order();
    void output(bool ifSelected);
};

template <typename T>
void bubblesort(T a[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(a[j]>a[j + 1]){
				T temp= a[j];
				a[j]=a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

bool stud::input() {
    if (isUsing) return 0;
    cout << "Id ";
    cin >> id;
    cout << "class ";
    cin >> cls;
    cout << "name ";
    cin >> name;
    cout << "score1 ";
    cin >> grade[0];
    cout << "score2 ";
    cin >> grade[1];
    cout << "score3 ";
    cin >> grade[2];
    isUsing = 1;
    setTotalGrade();
    return 1;
}

bool stud::operator>(const stud& a){
    double s1=cls*1000 - total;
    double s2=a.cls*1000 - a.total;
    if(s1>s2) return 1;
    return 0;
}

ostream& operator>>(ostream& output, const stud& stu) {
    if (stu.isUsing)
        output << stu.id << "," << stu.cls << "," << stu.name << "," << fixed << setprecision(1)
               << stu.grade[0] << "," << stu.grade[1] << "," << stu.grade[2] << "," << stu.total
               << "\n";
    return output;
}

bool stud::match(int select) {
    if (!isUsing || (select != id && select != cls)) return 0;
    isSelected = 1;
    return 1;
}

void grade::input() {
    for (int i = 0; i < MAXSTU; i++) {
        if (stu[i].input()) break;
        if (i == 4) cout << "Unable to add more students." << endl;
    }
}

void grade::del() {
    int inputId;
    cin >> inputId;
    if (cin) {
        for (int i = 0; i < MAXSTU; i++) stu[i].del(inputId);
    } else {
        string inputName;
        cin >> inputName;
        for (int i = 0; i < MAXSTU; i++) stu[i].del(inputName);
    }
    output(0);
}

void grade::select() {
    int input;
    cin >> input;
    bool ifFound = 0;
    for (int i = 0; i < MAXSTU; i++) {
        stu[i].setIsSelected();
        if (stu[i].match(input)) ifFound = 1;
    }
    if (ifFound)
        output(1);
    else
        cout << "there is no eligible student" << endl;
}

void grade::order() {
    bubblesort(stu,MAXSTU);
    output(0);
}

void grade::output(bool ifSelected) {
    // 参数的为0时，输出全部isUsing=1的学生
    // 参数为1时输出 isUsing && isSelected 的学生
    if (ifSelected) {
        for (int i = 0; i < MAXSTU; i++)
            if (stu[i].getIsSelected()) cout >> stu[i];
    } else
        for (int i = 0; i < MAXSTU; i++) cout >> stu[i];
}

int main() {
    grade gra;
    char menu[256] =
        "1.input\n2.delete\n3.select\n4.order\n5.output\n6.quit\nplease input "
        "your option\n";
    int cata;
    for (;;) {
        cout << menu;
        cin >> cata;
        bool ifContinue = 1;
        int i = 0;
        do {
            switch (cata) {
                case 1:
                    gra.input();
                    break;
                case 2:
                    gra.del();
                    break;
                case 3:
                    gra.select();
                    break;
                case 4:
                    gra.order();
                    break;
                case 5:
                    gra.output(0);
                    break;
                case 6:
                    return 0;
                default:
                    cout << "Wrong input, please try again. " << endl;
            }
            if (cata == 4 || cata == 5) break;
            string option;
            cout << "continue?\n";
            cin >> option;
            if (option == "yes")
                ifContinue = 1;
            else
                ifContinue = 0;
            i++;
        } while (ifContinue);
    }
}