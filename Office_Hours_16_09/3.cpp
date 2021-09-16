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

#define ld                  long double
#define pii                 pair<int, int>
#define vt                  vector
#define ll                  long long
#define ordered_set         tree < pair<pair<int, int>, int>,  null_type ,  less<pair<pair<int, int>, int> > ,  rb_tree_tag ,  tree_order_statistics_node_update >


const int MAX = 1e9;
const int MOD = 1e9 + 7;
const int BINT = 32;
const int BLONG = 64;
const ll  INF = 1e18;
const ld  PI  = 3.14159265358979323846;
 
template<typename T>
void read(vt<T> & a) {
    For(i, a.size()) cin >> a[i];
}
template<typename T>
void print(vt<T> & a) {
    For(i, a.size()) cout << a[i] << " ";
    cout << endl;
}
template<typename T>
void print2(vt<vt<T> > & a) {
    For(i, a.size()) {
        For(j, a[i].size()) cout << a[i][j] << " ";
        cout << endl;
    }
}

struct Node {
    string data;
    int count;
    Node *next;

    Node(string data) {
        this->data = data;
        this->next = nullptr;
        this->count = 1;
    }
};

struct WordStack {
    Node *root;
    int size;

    WordStack() {
        this->root = nullptr;
        this->size = 0;
    }

    void push(string data) {
        if (root == nullptr) {
            Node *node = new Node(data);
            root = node;
            return; 
        }
        if (root->data > data) {
            Node *node = new Node(data);
            node->next = root;
            root = node;
            return;
        }
        Node *temp = root;
        if (root->data == data) {
            root->count++;
            return;
        }
        while (temp->next && temp->next->data <= data) {
            if (temp->next->data == data) {
                temp->next->count++;
                return;
            }
            temp = temp->next;
        }
        Node *node = new Node(data);
        Node *next = temp->next;
        temp->next = node;
        node->next = next;
    }

    void show() {
        Node *cur = root;
        while (cur) {
            cout << cur->data << " " << cur->count << endl;
            cur = cur->next;
        }
    }
};

struct CountStack {
    Node *root;
    int size;

    CountStack() {
        this->root = nullptr;
        this->size = 0;
    }

    void push(Node *node) {
        if (root == nullptr) {
            root = node;
            return;
        }
        if (node->count > root->count) {
            node->next = root;
            root = node;
            return;
        }
        Node *temp = root;
        while (temp->next && temp->next->count >= node->count) {
            temp = temp->next;
        } 
        Node *next = temp->next;
        temp->next = node;
        node->next = next;
    }

    void show() {
        Node *cur = root;
        while (cur) {
            cout << cur->data << " " << cur->count << endl;
            cur = cur->next;
        }
    }
};

void write()
{
    string str;
    WordStack st1 = WordStack();
    CountStack st2 = CountStack();
    while (cin >> str) {
        st1.push(str);
    }
    Node *cur = st1.root;
    // st1.show();
    while (cur) {
        Node *node = new Node(cur->data);
        node->count = cur->count;
        st2.push(node);
        cur = cur->next;
    }
    st2.show();
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
// #endif
    int T;
    T = 1;
    // cin >> T;
    For(t, T) write();
    return 0;
}