#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int MOD = 1e9 + 7;

struct Car {
    int w, s, fc;

    friend bool operator< (Car & a, Car & b) {
        if (a.w < b.w) {
            return true;
        }
        if (a.w > b.w) {
            return false;
        }

        if (a.s > b.s) {
            return true;
        }
        if (a.s < b.s) {
            return false;
        }

        if (a.fc < b.fc) {
            return true;
        }
        return false;
    }
};

// w[i] < w[i + 1]
// s[i] > s[i + 1]
// fc[i] < fc[i + 1]

template<typename T>
void merge_sort(int l, int r, vt<T> a) {
	if (l >= r) {
		return; 
	}
	int m = (l + r)>>1;
	merge_sort(l, m, a);
	merge_sort(m + 1, r, a);
	int l2 = l, m2 = m + 1;
	vt<T> b;
	while (l2 <= m && m2 <= r) {
		if (a[l2] < a[m2]) {
			b.push_back(a[l2]);
			l2++;
		} else {
			b.push_back(a[m2]);
			m2++;
		}
	}
	while (l2 <= m) {
		b.push_back(a[l2]);
		l2++;
	}
	while (m2 <= r) {
		b.push_back(a[m2]);
		m2++;
	}
	for (int i = 0; i < b.size(); ++i) {
		a[l + i] = b[i];
	}
} 

int main()
{
    int n;
    cin >> n;
    vt<Car> a(n);
    For(i, n) {
        a[i].w  = rand() % 10 + 1;
        a[i].s  = rand() % 10 + 1;
        a[i].fc = rand() % 10 + 1;
    }
    merge_sort(0, n - 1, a);
    For(i, n) {
        cout << " " << a[i].w << " " << a[i].s << " " << a[i].fc << endl;
    }
    return 0;
}