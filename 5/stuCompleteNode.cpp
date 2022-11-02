#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

struct student {
    int id, cls;
    string name;
    float s1, s2, s3, sort;
    bool selected;
    student *next;
};

student *input(student *head);
student *del(student *head);
void select(student *head);
void output(student *head);
student *sortnode(student *head);
void editSelectTrue(student *head);

int main() {
    student *head = NULL;
    char menu[256] =
        "1.input\n2.delete\n3.select\n4.order\n5.output\n6.quit\nplease input "
        "your option\n";
    int cata;
    while (1) {
        cout << menu;
        cin >> cata;
        switch (cata) {
            case 1:
                head = input(head);
                break;
            case 2:
                head = del(head);
                break;
            case 3:
                select(head);
                break;
            case 4:
                head = sortnode(head);
                break;
            case 5:
                output(head);
                break;
            case 6:
                return 0;
        }
    }
}

student *input(student *head) {
    student *p1, *p2;
    p1 = p2 = new student;
    head = p1;
    while (1) {
        string in;
        cout << "Id ";
        cin >> p1->id;
        cout << "class ";
        cin >> p1->cls;
        cout << "name ";
        cin >> p1->name;
        cout << "score1 ";
        cin >> p1->s1;
        cout << "score2 ";
        cin >> p1->s2;
        cout << "score3 ";
        cin >> p1->s3;
        p1->sort = float(p1->cls * 1000) - p1->s1 - p1->s2 - p1->s3;
        cout << "continue?\n";
        cin >> in;
        if (in == "yes") {
            p1 = new student;
            p2->next = p1;
            p2 = p1;
        } else {
            p1->next = NULL;
            return head;
        }
    }
}

student *del(student *head) {
    while (1) {
        student *p1, *p2;
        p1 = head;
        int nin;
        string strin = "+";
        cin >> nin;
        if (!cin) {
            cin.clear();
            nin = -1;
            cin >> strin;
        }
        do {
            if ((strin == "+" && nin == p1->id) ||
                (nin == -1 && strin == p1->name)) {
                if (p1 == head) {
                    head = p1->next;
                    delete p1;
                    p1 = head;
                } else {
                    p2->next = p1->next;
                    delete p1;
                    p1 = p2->next;
                }
            } else {
                p2 = p1;
                if (p1 != NULL) p1 = p1->next;
            }
        } while (p1 != NULL);
        editSelectTrue(head);
        output(head);
        string in;
        cout << "continue?\n";
        cin >> in;
        if (in == "no") return head;
    }
}

void select(student *head) {
    while (1) {
        bool flag = 0;
        int in;
        cin >> in;
        student *p;
        p = head;
        do {
            if (p->id == in || p->cls == in) {
                p->selected = 1;
                flag = 1;
            } else
                p->selected = 0;
            p = p->next;
        } while (p != NULL);
        if (flag)
            output(head);
        else
            cout << "there is no eligible student" << endl;
        string strin;
        cout << "continue?\n";
        cin >> strin;
        if (strin == "no") return;
    }
}

student *sortnode(student *head) {
    student *p1, *p2;
    p1 = head;
    do {
        p2 = p1;
        p1 = p1->next;
        if (p1->sort < p2->sort) {
            student *ins;
            ins = head;
            if (p1->sort < ins->sort) {
                p2->next = p1->next;
                head = p1;
                p1->next = ins;
                p1 = p2->next;
            } else {
                do {
                    if (p1->sort < ins->next->sort) {
                        p2->next = p1->next;
                        p1->next = ins->next;
                        ins->next = p1;
                        p1 = p2->next;
                    } else {
                        ins = ins->next;
                    }
                } while (ins->next != p2);
            }
        } else {
            p1 = p1->next;
            p2 = p2->next;
        }
    } while (p1 != NULL);
    editSelectTrue(head);
    output(head);
    return head;
}

void editSelectTrue(student *head) {
    student *p;
    p = head;
    do {
        p->selected = 1;
        p = p->next;
    } while (p != NULL);
}

void output(student *head) {
    student *p;
    p = head;
    do {
        if (p->selected)
            cout << p->id << "," << p->cls << "," << p->name << "," << fixed
                 << setprecision(1) << p->s1 << "," << p->s2 << "," << p->s3
                 << "," << p->s1 + p->s2 + p->s3 << "\n";
        p = p->next;
    } while (p != NULL);
}