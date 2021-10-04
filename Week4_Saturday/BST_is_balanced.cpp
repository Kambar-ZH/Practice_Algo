#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb(i)               push_back(i)
#define For(i, n)           for(int i = 0; i < n; ++i)

struct Node {
	int val;
	Node * left, * right;
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

	int depth(Node *root) {
		if (root == nullptr) {
			return 0;
		}
		return max(depth(root->left), depth(root->right)) + 1;
	}

	int depth() {
		return depth(root);
	}

	bool is_balanced(Node* root) { 			// Не оптимальное решение, время работы O(N ^ 2)
		if (root == nullptr) {			// Попробуй хранить высоту каждой ноды, без вызова функции depth 
			return true;
		}
		int left_d = depth(root->left); 	// Берем высоту левого поддерева
		int right_d = depth(root->right); 	// Берем высоту правого поддерева
		return abs(left_d - right_d) <= 1 	// Проверяем на условие того что дерево сбалансированное
			&& is_balanced(root->left)   	// Проверяем на сбалансированность левое поддерево
			&& is_balanced(root->right); 	// Проверяем на сбалансированность правое поддерево
						    	// так как они могут быть не сбалансированными
	}
	
	bool is_balanced() {
		return is_balanced(root);
	}
};

int main()
{
	freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
	int n;
	BST bst = BST();
	while (cin >> n) {
		if (n == 0) break;
		bst.add(n);
	}
	if (bst.is_balanced()) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}