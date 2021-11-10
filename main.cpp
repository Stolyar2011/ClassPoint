#define _GLIBCXX_DEBUG
#include <iostream>
#include <string>
#include <vector>

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
        Node* x = new Node;
        x -> data = a;
        x -> next = head;
        head = x;
        n++;
    }

    void push_back(string& a) {
        Node* x = new Node;
        x -> data = a;
        if(n != 0) {
            Node *node = head;
            for (int i = 0; i < n - 1; i++) {
                node = node->next;
            }
            node->next = x;
        } else {
            head = x;
        }
        n++;
    }

    void push_pos(string& a, int k) {
        Node* x = new Node;
        x -> data = a;
        if (k <= n) {
            if (k != 0) {
                Node* node = head;
                for (int i = 0; i < k - 1; i++) {
                    node = node -> next;
                }
                auto next_elem = node -> next;
                x -> next = next_elem;
                node -> next = x;
                n++;
            } else {
                push_front(a);
            }
        }
    }

    void pop_front() {
        if (n != 0) {
            delete head;
            head = head -> next;
            n--;
        }
    }

    void pop_back() {
        if (n != 0) {
            Node* node = head;
            for (int i = 0; i < n - 1; i++) {
                node = node -> next;
            }

        }
    }

    void pop_pos(int k) {
        if (k <= n) {
            Node* node = head;
            for (int i = 0; i < k - 1; i++) {
                node = node -> next;
            }
            Node* next_elem = node -> next -> next;
            delete node -> next;
            node -> next = next_elem;
            n--;
        }
    }

    void pop_value(string& a) {
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

    int find_pos(string& a) {
        Node* node = head;
        for (int i = 0; i < n; i++) {
            if (node->data == a) {
                return i;
            }
            node = node->next;
        }
        return -1;
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

ostream& operator<< (ostream& out, List &lis) {
    Node* node = lis.head;
    while (node != nullptr) {
        out << node -> data << ' ';
        node = node -> next;
    }
    return out;
}

int main() {
    List lis;
    string back, front, index, delete_by_value;
    int k, from_front, from_back, by_index;
    string s = "counter";
    lis.push_back(s);
    cout << "Введем список";
    vector<string> memory = {"apple", "home", "robbery", "car", "point", "vector", "internet"};
    for (auto q : memory) {
        lis.push_back(q);
    }

    cout << "Введите строку, которая будет добавлена в конец списка: ";
    getline(cin, back);
    cout << "Введите строку, которая будет добавлена в начало списка: ";
    getline(cin, front);
    cout << "Введите в отдельных строках, строку и индекс принадлежащий интервалу [0, 8]";
    getline(cin, index);
    cin >> k;
    lis.push_back(back);
    lis.push_front(front);
    lis.push_pos(index, k);

    cout << "Выведем список и его длину: " << lis.n << '\n' << lis << endl;
    cout << "Введите строку, которую хотите удалить по значению ";
    getline(cin, delete_by_value);
    getline(cin, delete_by_value);
    cout << "Введите колличество элементов, которые вы хотите удалить из начала списка ";
    cin >> from_front;
    cout << "Введите колличество элементов, которые вы хотите удалить из конца списка ";
    cin >> from_back;
    cout << "Введите индекс элемента, который будет удален ";
    cout << "Удалим все эти элементы";
    lis.pop_value(delete_by_value);
    for (int i = 0; i < from_front; i++) {
        lis.pop_front();
    }
    for (int i = 0; i < from_back; i++) {
        lis.pop_back();
    }
    lis.pop_pos(by_index);
    cout << "Выведем список на экран " << lis;
    cout << "Введите строку, индекс которой вы хотите найти в списке ";
    string find;
    getline(cin, find);
    getline(cin, find);
    k = lis.find_pos(find);
    if (k == -1) {
        cout << "Такой строки нет в списке" << '\n';
    } else {
        cout << "Инлекс данной строки в списке: " << k << '\n';
    }
}
