#include <bits/stdc++.h>
using namespace std;
#define For(i, n)           for(int i = 0; i < n; ++i)

struct Heap
{
    vector<int> heap;
    int size = 0;
    Heap() {
        heap.push_back(0);
    }
    void insert(int data) {
        heap.push_back(data);
        int index = heap.size() - 1;
        shift_up(index);
        size++;
    } 

    void shift_up(int index) {
        if (index == 1) {
            return;
        }
        int parent = index / 2;
        if (heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            shift_up(parent);
        }
    }

    void del() {
        swap(heap[1], heap.back());
        heap.pop_back();
        shift_down(1);
        size--;
    }

    void shift_down(int index) {
        if (index * 2 >= heap.size()) {
            return;
        }
        int smallest = index;
        int c1 = index * 2;
        int c2 = index * 2 + 1;
        if (heap[smallest] > heap[c1]) {
            smallest = c1;
        } 
        if (c2 < heap.size() && heap[smallest] > heap[c2]) {
            smallest = c2;
        }
 
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            shift_down(smallest);
        }
    }

    int getRoot() {
        if (size == 0) {
            return -1;
        }
        return heap[1];
    }
};

int main()
{
    int n; cin >> n;
    Heap hp = Heap();
    For(i, n) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            hp.insert(x);
            cout << "minimum number in heap: " << hp.getRoot() << endl;
        } else {
            hp.del();
            cout << "minimum number in heap: " << hp.getRoot() << endl;
        }
    }
    return 0;
}