#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb(i)               push_back(i)
#define For(i, n)           for(int i = 0; i < n; ++i)

struct Node {
	string data;
	int count;
	Node *prev, *next;
	Node(string data) {
		this->data = data;
		this->count = 1;
		prev = next = nullptr;
	}
};

struct LinkedList {
	Node *root;
	LinkedList() {
		this->root = nullptr;
	}

	void push(string data) {
		if (root == nullptr) {
			root = new Node(data);
			return;
		}
		if (root->data > data) {
			Node* node = new Node(data);
			node->next = root;
			root = node;
			return;
		}
		if (root->data == data) {
			root->count++;
			return;
		}
		Node* temp = root;
		while (temp->next && temp->next->data <= data) {
			if (temp->next->data == data) {
				temp->next->count++;
				return;
			}
			temp = temp->next;
		}
		Node *next = temp->next;
		Node *node = new Node(data);
		temp->next = node;
		node->next = next;
	}

	void show() {
		Node *temp = root;
		while (temp != nullptr) {
			cout << temp->data << " " << temp->count << endl;
			temp = temp->next;
		}
	}
};

struct LinkedListCount {
	Node *root;
	LinkedListCount() {
		this->root = nullptr;
	}

	void push(Node *node) {
		if (root == nullptr) {
			root = node;
			return;
		}
		if (root->count < node->count) {
			node->next = root;
			root = node;
			return;
		}
		Node *temp = root;
		while (temp->next != nullptr) {
			if (temp->next->count < node->count) {
				break;
			}
			temp = temp->next;
		}
		Node *next = temp->next;
		temp->next = node;
		node->next = next;
	}

	void show() {
		Node *temp = root;
		while (temp != nullptr) {
			cout << temp->data << " " << temp->count << endl;
			temp = temp->next;
		}
	}
};

int main()
{
	freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
	LinkedList ll = LinkedList();
	string line;
	while (cin >> line) {
		ll.push(line);
	}
	// ll.show();
	// cout << endl;
	LinkedListCount ll2 = LinkedListCount();
	Node *temp = ll.root;
	while (temp) {
		Node *node = new Node(temp->data);
		node->count = temp->count;
		ll2.push(node);
		temp = temp->next;
	} 
	ll2.show();
	return 0;
}