#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int MOD = 1e9 + 7;

int partition(int l, int r, vt<int> & a) {
	int i = l;
	int p = r;
	for (int j = l; j < r; ++j) {
		if (a[j] < a[p]) {
			swap(a[j], a[i]);
			i++;
		}
	}
	swap(a[i], a[p]);
	return i;
}

void quick_sort(int l, int r, vt<int> & a) {
	if (l >= r) return;
	int pivot = partition(l, r, a);
	quick_sort(l, pivot - 1, a);
	quick_sort(pivot + 1, r, a);
}

int main()
{	
	int n; cin >> n;
	vt<int> a(n);
	For(i, n) a[i] = rand() % 100 + 1;
	random_shuffle(a.begin(), a.end());
	For(i, n) cout << a[i] << " ";
	cout << endl;
	quick_sort(0, n - 1, a);
	For(i, n) cout << a[i] << " ";
	return 0;
}