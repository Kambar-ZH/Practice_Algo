#include <bits/stdc++.h>

using namespace std;

#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)

struct Time {
    int hours, minutes, seconds;
    Time(int hours, int minutes, int seconds) {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }
    Time() {

    }

    friend bool operator<(Time &a, Time &b) {
        return a.hours * 60 * 60 + a.minutes * 60 + a.seconds < b.hours * 60 * 60 + b.minutes * 60 + b.seconds;
    }
};

struct Car {
    int weight, max_speed, fuel_consumption;
    Car() {

    }
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
void merge_sort(int l, int r, vt<T> & a) {
    if (l >= r) {
        return;
    }
    int m = (l + r)>>1;
    
    merge_sort(l, m, a); 
    merge_sort(m + 1, r, a); 
    int left = l, middle = m + 1;
    vt<T> b;
    while (left <= m && middle <= r) {
        if (a[left] < a[middle]) {
            b.push_back(a[left]);
            left++;
        } else {
            b.push_back(a[middle]);
            middle++;
        }
    }
    while (left <= m) {
        b.push_back(a[left]);
        left++;
    }
    while (middle <= r) {
        b.push_back(a[middle]);
        middle++;
    }
    for (int i = 0; i < b.size(); ++i) {
        a[i + l] = b[i];
    }
}
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

int main()
{
    int n; cin >> n;
    vt<Car> a(n);
    For(i, n) {
        a[i].weight = rand() % 5 + 1;
        a[i].max_speed = rand() % 5 + 1;
        a[i].fuel_consumption = rand() % 5 + 1;
    }
    vt<Time> b(n);
    For(i, n) {
        b[i].hours = rand() % 5 + 1;
        b[i].minutes = rand() % 5 + 1;
        b[i].seconds = rand() % 5 + 1;
    }
    vt<int> c(n);
    For(i, n) {
        c[i] = rand() % 100 + 1;
    }
    // Sort integers
    quick_sort(0, n - 1, c);
    For(i, n) cout << c[i] << " ";
    cout << endl;
    // Sort Cars
    quick_sort(0, n - 1, a);
    cout << "CARS" << endl;
    For(i, n) {
        printf("%d %d %d\n", a[i].weight, a[i].max_speed, a[i].fuel_consumption);
    }
    // Sort Times
    quick_sort(0, n - 1, b);
    cout << "TIMES" << endl;
    For(i, n) {
        printf("%d %d %d\n", b[i].hours, b[i].minutes, b[i].seconds);
    }
    return 0;
}