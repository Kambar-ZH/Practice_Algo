#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb(i)               push_back(i)
#define For(i, n)           for(int i = 0; i < n; ++i)
#define qFor(i, x, n)       for(int i = x; i < n; ++i)
#define rFor(i, n)          for(int i = n - 1; i >= 0; --i)
#define see                 cout << endl;
#define all(x)              (x).begin(),(x).end()
#define rall(x)             (x).rbegin(),(x).rend()
#define ls x + x
#define rs x + x + 1

struct Node {
    string data;
    Node *next, *prev;

    Node(string data) { // fields
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    void printInfo() {
        cout << "My data " << data << endl;
    }
};

struct MyDeque {
    Node *root;
    int sz;

    void push(string &data, int pos) { // Поставить ноду под индексом pos
        if (root == nullptr) {
            root = new Node(data);
            return;
        }
        Node *node = new Node(data); // Новая нода
        if (pos == 1) {
            node->next = root;
            root->prev = node;
            return;
        }
        int itr = 1;
        Node *temp = root;
        while (temp != nullptr) {
            if (itr == pos - 1) {
                Node *next = temp->next;
                temp->next = node;
                node->prev = temp;
                node->next = next;
                if (next != nullptr) { // мы не можем обратить к полю prev если нода это nullptr
                    next->prev = node;
                }
                return;
            }
            itr++;
            temp = temp->next;
        }
    }

    void del(int pos) {
        Node *temp = root;
        if (pos == 1) { // Если удаляем root
            Node *toDelete = root;
            root = root->next;
            delete(toDelete); // oчищаем память чтобы не было утечек
            return;
        }
        int itr = 1;
        while (temp) {
            if (itr == pos) {
                Node *prev = temp->prev;
                Node *next = temp->next;
                delete(temp);
                if (prev != nullptr) {
                    prev->next = next;
                }
                if (next != nullptr) {
                    next->prev = prev;
                }
                return;
            }
            itr++;
            temp = temp->next;
        }
    }

    void replace(string &data, int pos) {
        Node *temp = root;
        int itr = 1;
        while (temp != nullptr) {
            if (itr == pos) {
                temp->data = data;
                return;
            }
            itr++;
            temp = temp->next;
        }
    }

    void print() {
        Node *temp = root;
        while (temp) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

void write()
{
    int n;
    cin >> n;
    MyDeque dq = MyDeque();
    For(i, n) {
        int pos; string data;
        cin >> pos >> data;
        dq.push(data, pos);
    }
    dq.print();
    For(i, n) {
        int pos; string data;
        cin >> pos >> data;
        dq.replace(data, pos);
        dq.print();
    }
    dq.print();
    For(i, n) {
        int pos;
        cin >> pos;
        dq.del(pos);
        dq.print();
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int T;
    T = 1;
    For(t, T) write();
    return 0;
}
