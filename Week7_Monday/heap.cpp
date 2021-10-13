#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int MOD = 1e9 + 7;

struct Heap {
	vt<int> heap;

	void push(int data) {
		heap.push_back(data);
		int root = heap.size() - 1;
		shift_up(root);
	}

	void del() {
		int last = heap.size() - 1;
		int root = 0;
		swap(heap[last], heap[root]);
		heap.pop_back();
		shift_down(root);
	}

	void shift_down(int root) {
		if (root + root + 1 >= heap.size()) {
			return;
		}
		int ch1 = root + root + 1;
		int ch2 = root + root + 2;
		int smallest = root;
		if (heap[smallest] > heap[ch1]) {
			smallest = ch1;
		}
		if (ch2 < heap.size() && heap[smallest] > heap[ch2]) {
			smallest = ch2;
		}
		if (smallest != root) {
			swap(heap[root], heap[smallest]);
			shift_down(smallest);
		}
	}

	void shift_up(int root) {
		if (root == 0) {
			return;
		}
		int parent = (root - 1) / 2;
		if (heap[parent] > heap[root]) {
			swap(heap[parent], heap[root]);
			shift_up(parent);
		}
	}

	int top() {
		return heap[0];
	}

	void sort() {
		while (!heap.empty()) {
			cout << top() << " ";
			del();
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
