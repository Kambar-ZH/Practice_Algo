#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int MOD = 1e9 + 7;

void merge_sort(int l, int r, vt<int> & a) {
	if (l >= r) {
		return; 
	}
	int m = (l + r)>>1;
	merge_sort(l, m, a);
	merge_sort(m + 1, r, a);
	int l2 = l, m2 = m + 1;
	vt<int> b;
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
	int n; cin >> n;
	vt<int> a(n);
	For(i, n) a[i] = rand() % 100 + 1;
	random_shuffle(a.begin(), a.end());
	For(i, n) cout << a[i] << " ";
	cout << endl;
	merge_sort(0, n - 1, a);
	For(i, n) cout << a[i] << " ";
	return 0;
}