#include <bits/stdc++.h>

using namespace std;

#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)

struct Car {
    int weight, max_speed, fuel_consumption;

    friend bool operator<(Car &a, Car &b) {
        if (a.weight < b.weight) {
            return true;
        }
        if (a.weight > b.weight) {
            return false;
        }
        if (a.max_speed < b.max_speed) {
            return false;
        }
        if (a.max_speed > b.max_speed) {
            return true;
        }
        if (a.fuel_consumption < b.fuel_consumption) {
            return true;
        }
        return false;
    }
};

template<typename T>
int partition(int l, int r, vt<T> & a) {
    int j = l;
    swap(a[l], a[r]);
    for (int i = l; i < r; ++i) {
        if (a[i] < a[r]) {
            swap(a[j], a[i]);
            j++;
        }
    }
    swap(a[j], a[r]);
    return j;
}

template<typename T>
void quick_sort(int l, int r, vt<T> & a) {
    if (l >= r) {
        return;
    }
    int p = partition(l, r, a);
    quick_sort(l, p - 1, a);
    quick_sort(p + 1, r, a);
}

void sort_cars(int n) {
    vt<Car> a(n);
    For(i, n) {
        a[i].weight = rand() % 1000 + 1;
        a[i].max_speed = rand() % 200 + 1;
        a[i].fuel_consumption = rand() % 10 + 1;
    }
    quick_sort(0, n - 1, a);
    cout << "CARS" << endl;
    For(i, n) {
        printf("%d %d %d\n", a[i].weight, a[i].max_speed, a[i].fuel_consumption);
    }
}

void sort_integers(int n) {
    vt<int> c(n);
    For(i, n) {
        c[i] = rand() % 100 + 1;
    }
    cout << "INTEGERS" << endl;
    quick_sort(0, n - 1, c);
    For(i, n) cout << c[i] << " ";
    cout << endl;
}

int main()
{
    int n; cin >> n;
    sort_cars(n);
    sort_integers(n);
    return 0;
}