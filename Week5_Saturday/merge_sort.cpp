#include <bits/stdc++.h>

using namespace std;

#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)

struct Time {
    int hours, minutes, seconds;

    friend bool operator<(Time &a, Time &b) {
        return a.hours * 60 * 60 + a.minutes * 60 + a.seconds < b.hours * 60 * 60 + b.minutes * 60 + b.seconds;
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

void sort_times(int n) {
    vt<Time> b(n);
    For(i, n) {
        b[i].hours = rand() % 24 + 1;
        b[i].minutes = rand() % 60 + 1;
        b[i].seconds = rand() % 60 + 1;
    }
    merge_sort(0, n - 1, b);
    cout << "TIMES" << endl;
    For(i, n) {
        printf("%d %d %d\n", b[i].hours, b[i].minutes, b[i].seconds);
    }
}

int main()
{
    int n; cin >> n;
    sort_times(n);
    return 0;
}