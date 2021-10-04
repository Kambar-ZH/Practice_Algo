#include <bits/stdc++.h>
using namespace std;
#define For(i, n)           for(int i = 0; i < n; ++i)

struct Heap
{
    vector<int> heap; // храним наши элементы внутри вектора
    int size = 0;
    Heap() {
        heap.push_back(0); // добавляем 0 чтобы была индексация с 1, а не с 0
    }
    void insert(int data) {
        heap.push_back(data); // добавляем элемент в конец
        int index = heap.size() - 1;
        shift_up(index); // тут мы его поднимаем наверх
        size++;
    } 

    void shift_up(int index) {
        if (index == 1) {
            return;
        }
        int parent = index / 2;
        if (heap[index] < heap[parent]) { // если элемент меньше чем его родитель меняем их местами
            swap(heap[index], heap[parent]);
            shift_up(parent); // идем в индекс родителя и проводим shift_up
        }
    }

    void del() {
        if (size == 0) {
            cout << "ERROR" << endl;
            return;
        }
        swap(heap[1], heap.back()); // убираем старый минимум в конец вектора
        heap.pop_back(); // удаляем его
        shift_down(1); // пытаемся опустить элемент вниз
        size--;
    }

    void shift_down(int index) {
        if (index * 2 >= heap.size()) {
            return;
        }
        int smallest = index;
        int c1 = index * 2; // левый ребенок
        int c2 = index * 2 + 1; // правый ребенок
        if (heap[smallest] > heap[c1]) { 
            smallest = c1;
        } 
        if (c2 < heap.size() && heap[smallest] > heap[c2]) {
            smallest = c2;
        }
 
        if (smallest != index) { // если нашелся ребенок, у которого значение меньше чем у родителя, то свапаем их и проводим shift_down для ребенка
            swap(heap[index], heap[smallest]);
            shift_down(smallest);
        }
    }

    int get_root() {
        if (size == 0) {
            return -1;
        }
        return heap[1]; // выводим root, в данном случаи он находится под индексом 1
    }
};

void heap_sort() {
    Heap hp = Heap(); // min Heap
    int n; cin >> n;
    For(i, n) {
        int x; cin >> x;
        hp.insert(x);
    }
    For(i, n) {
        cout << hp.get_root() << " "; // get smallest in Heap
        hp.del(); // delete smallest in Heap
    }
}

int main()
{
//     heap_sort();
    int n; cin >> n;
    Heap hp = Heap();
    For(i, n) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            hp.insert(x);
            cout << "minimum number in heap: " << hp.get_root() << endl;
        } else {
            hp.del();
            cout << "minimum number in heap: " << hp.get_root() << endl;
        }
    }
    return 0;
}
