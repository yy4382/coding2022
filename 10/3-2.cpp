#include <iostream>
using namespace std;
#define nullptr NULL
struct Node {
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int data_) : data(data_), next(nullptr) {}
};
class LinkedList {
   private:
    Node* head;

   public:
    LinkedList() { head = new Node; }
    int AddNode(Node* node);
    int DeleteNodeByData(int data);
    void PrintList();
};

int LinkedList::AddNode(Node* node) {
    if (head->next == nullptr) {
        head->next = node;
        return 1;
    }
    Node *cur, *pre;
    pre = head;
    cur = head->next;
    while (cur != nullptr) {
        if (node->data == cur->data) {
            delete node;
            return 0;
        }
        if (cur->data > node->data) {
            pre->next = node;
            node->next = cur;
            return 1;
        }
        pre = cur;
        cur = cur->next;
    }
    pre->next = node;
    return 1;
}

int LinkedList::DeleteNodeByData(int data) {
    Node *cur,*pre;
    pre=head;
    cur=head->next;
    while(cur!= nullptr){
        if(cur->data==data){
            pre->next=cur->next;
            delete cur;
            return 1;
        }
        pre=cur;
        cur=cur->next;
    }
    return 0;
}

void LinkedList::PrintList() {
    Node* cur = this->head->next;
    while (cur != nullptr) {
        cout << cur->data << endl;
        cur = cur->next;
    }
}

int main(int argc, char const* argv[]) {
    LinkedList list;
    int n, d;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d;
        Node* node = new Node(d);
        list.AddNode(node);
    }
    list.PrintList();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d;
        list.DeleteNodeByData(d);
    }
    list.PrintList();
    return 0;
}