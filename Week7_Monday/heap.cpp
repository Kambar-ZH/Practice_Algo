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
		int idx = heap.size() - 1;
		shift_up(idx);
	}

	void del() {
		int last = heap.size() - 1;
		int root = 0;
		swap(heap[last], heap[root]);
		heap.pop_back();
		shift_down(root);
	}

	void shift_down(int idx) {
		if (idx * 2 + 1 >= heap.size()) {
			return;
		}
		int left_ch = idx * 2 + 1;
		int right_ch = idx * 2 + 2;
		int min_idx = idx;
		if (heap[min_idx] > heap[left_ch]) {
			min_idx = left_ch;
		}
		if (right_ch < heap.size() && heap[min_idx] > heap[right_ch]) {
			min_idx = right_ch;
		}
		if (min_idx != idx) {
			swap(heap[idx], heap[min_idx]);
			shift_down(min_idx);
		}
	}

	void shift_up(int idx) {
		if (idx == 0) {
			return;
		}
		int parent_idx = idx / 2;
		if (heap[parent_idx] > heap[idx]) {
			swap(heap[parent_idx], heap[idx]);
			shift_up(parent_idx);
		}
	}

	int get_min() {
		return heap[0];
	}

	void sort() {
		while (!heap.empty()) {
			cout << get_min() << " ";
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
	For(i, n) cout << a[i] << " ";
	cout << endl;
	Heap hp = Heap();
	For(i, n) {
		hp.push(a[i]);
		cout << hp.get_min() << endl;
	}
	hp.sort();
	return 0;
}