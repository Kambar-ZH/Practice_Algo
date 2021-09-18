#include <bits/stdc++.h>
using namespace std;

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
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    write();
    return 0;
}
