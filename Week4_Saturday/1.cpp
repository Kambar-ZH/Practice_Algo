#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb(i)               push_back(i)
#define For(i, n)           for(int i = 0; i < n; ++i)

struct Node {
	int val;
	Node * left, * right;
	Node (int val, Node * left, Node * right) {
		this->val = val;
		this->left = left;
		this->right = right;
	}
    Node (int val) {
		this->val = val;
		this->left = nullptr;
		this->right = nullptr;
	}
};

struct BST{
	Node* root;
	BST() {
		root = nullptr;
	}

	Node* add(Node* root, int x) {
		if (root == nullptr) {
			return new Node(x);	
		}
		if (root->val > x) {
			root->left = add(root->left, x);
		} else if (root->val < x) {
			root->right = add(root->right, x);
		}
		return root;
	}

	Node* rightmost(Node* root) {
		while (root->right) {
			root = root->right;
		}
		return root;
	}

	Node* second_maximum(Node* root) {
		if (root->right != nullptr) {
			Node* parent = root;
			while (parent->right->right != nullptr) {
				parent = parent->right;
			}
			
			Node* right = parent->right;
			if (right->left == nullptr) {
				return parent;
			}
			return rightmost(right->left);
		} 
		return rightmost(root->left);
	}

	void add(int x) {
		root = add(root, x);
	}

	void print(Node* root, int level) {
		if (root) {
			print(root->left, level + 1);
			cout << root->val << " " << level << endl;
			print(root->right, level + 1);
		}
	} 

	int rightmost() {
		return rightmost(root)->val;
	}

	int second_maximum() {
		return second_maximum(root)->val;
	}

	void print() {
		print(root, 1);
	}
};

int main()
{
	freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
	int n;
	BST bst = BST();
	while (cin >> n) {
		bst.add(n);
	}
	// bst.print();
	cout << bst.second_maximum() << endl;
	return 0;
}