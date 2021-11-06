#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int MOD = 1e9 + 7;

struct Heap {
	vt<int> heap;

    int get_left_child(int node) {
        return node + node + 1;
    }

    int get_right_child(int node) {
        return node + node + 2;
    }

    int get_parent(int node) {
        return (node - 1) / 2;
    }

	void push(int data) {
		heap.push_back(data);
		int node = heap.size() - 1;
		shift_up(node);
	}

	void pop() {
        if (heap.empty()) {
            cout << "ERROR" << endl;
            return;
        }
		int last = heap.size() - 1;
		int node = 0;
		swap(heap[last], heap[node]);
		heap.pop_back();
		shift_down(node);
	}

	void shift_down(int node) {
		if (get_left_child(node) >= heap.size()) return;
		int ch1 = get_left_child(node);
		int ch2 = get_right_child(node);
		int smallest = node;
		if (heap[smallest] > heap[ch1]) {
			smallest = ch1;
		}
		if (ch2 < heap.size() && heap[smallest] > heap[ch2]) {
			smallest = ch2;
		}
		if (smallest != node) {
			swap(heap[node], heap[smallest]);
			shift_down(smallest);
		}
	}

	void shift_up(int node) {
		if (node == 0) return;
		int parent = get_parent(node);
		if (heap[parent] > heap[node]) {
			swap(heap[parent], heap[node]);
			shift_up(parent);
		}
	}

	int top() {
		return heap[0];
	}

	void sort() {
		while (!heap.empty()) {
			cout << top() << " ";
			pop();
		}
		cout << endl;
	}
};

int main()
{
	int n; cin >> n;
	vt<int> a(n);
	For(i, n) a[i] = rand() % 100 + 1;
	random_shuffle(a.begin(), a.end());
    	cout << "Random data: " << endl;
	For(i, n) cout << a[i] << " ";
	cout << endl;
	Heap hp = Heap();
	For(i, n) {
		hp.push(a[i]);
    	}
    	cout << "Sorted data: " << endl;
    	hp.sort();
	return 0;
}
