#include <iostream>
#include <string>

using namespace std;

struct Node{
    Node* next;
    string data;
    Node() {
        data = "";
        next = nullptr;
    }
};

struct List{
    Node* head;
    int n;
public:
    List() {
        head = nullptr;
        n = 0;
    }

    bool empty() {
        if (n == 0) {
            return true;
        }
        return false;
    }

    void push_front(string& a) {
        Node x;
        x.data = a;
        x.next = head;
        head = &x;
        n++;
    }

    void push_back(string& a) {
        Node x;
        x.data = a;
        Node* node = head;
        for (int i = 0; i < n - 1; i++) {
            node = node -> next;
        }
        node -> next = &x;
        n++;
    }

    void push_pos(string& a, int k) {
        Node x;
        x.data = a;
        if (k <= n) {
            if (k != 0) {
                Node* node = head;
                for (int i = 0; i < k - 1; i++) {
                    node = node -> next;
                }
                auto next_elem = node -> next;
                x.next = next_elem;
                node -> next = &x;
                n++;
            } else {
                push_front(a);
            }
        }
    }

    void pop_front() {
        if (n != 0) {
            head = (*head).next;
            n--;
        }
    }

    void pop_back() {
        if (n != 0) {
            Node* node = head;
            for (int i = 0; i < n - 1; i++) {
                node = node -> next;
            }
            node -> next = node -> next -> next;
            n--;
        }
    }

    void pop_pos(int k) {
        if (k <= n) {
            Node* node = head;
            for (int i = 0; i < k - 1; i++) {
                node = node -> next;
            }
            node -> next = (*node -> next).next;
            n--;
        }
    }

    void pop_value(string a) {
        Node* node = head;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (node -> data == a) {
                index = i;
            }
            node = node -> next;
        }
        if (index != -1) {
            pop_pos(index);
        }
    }

    int find_pos(string a) {
        Node* node = head;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (node->data == a) {
                index = i;
            }
            node = node->next;
        }
        return index;
    }

    string& operator[] (int index);
    friend ostream& operator<< (std::ostream &out, List &list);
};

string& List::operator[](int index) {
    Node* node = head;
    for (int i = 0; i < index; i++) {
        node = node -> next;
    }
    return (*node).data;
}

ostream& operator<< (ostream& out, List &list) {
    for (int i = 0; i < list.n; i++) {
        out << list[i];
    }
    return out;
}

int main() {
    List list;
    cout << "List.empty with empty list " << list.empty() << '\n';
    string a = "counter";
    list.push_front(a);
    cout << "first elem by head " << list.n << ' ' << (*list.head).data <<  '\n';
}