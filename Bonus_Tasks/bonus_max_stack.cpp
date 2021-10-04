#include <bits/stdc++.h>
using namespace std;

#define For(i, n)           for(int i = 0; i < n; ++i)
#define see                 cout << endl;
#define vt                  vector
const int MAX = 1e9;
template<typename T>
void read(vt<T> & a) {
	For(i, a.size()) cin >> a[i];
}

ll stupid(vt<int> & a) {
	int n = a.size();
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			int mn = MAX;
			ll sum = 0;
			for (int z = i; z <= j; z++) {
				mn = min(mn, a[z]);
				sum += a[z];
				res = max(res, sum * 1ll * mn);
			}
		}
	}
	return res;
}

int main()
{
	int n; cin >> n;
	vt<int> a(n); read(a);
	vt<int> b(n), c(n, n);
	deque<int> dq;
	dq.push_back(0);
	for (int i = 1; i < n; ++i) {
		while (!dq.empty() && a[dq.back()] >= a[i])
		{
			dq.pop_back();
		}
		if (!dq.empty()) {
			b[i] = dq.back() + 1;
		}
		dq.push_back(i);
	}
	dq.clear();
	dq.push_back(0);
	reverse(all(a));
	for (int i = 1; i < n; ++i) {
		while (!dq.empty() && a[dq.back()] >= a[i])
		{
			dq.pop_back();
		}
		if (!dq.empty()) {
			c[i] = n - dq.back() - 1;
		}
		dq.push_back(i);
	}
	reverse(all(a));
	reverse(all(c));
	vt<ll> pf(n + 1);
	For(i, n) {
		pf[i + 1] = pf[i] + a[i];
	}
	ll mx = 0;
	For(i, n) {
		int l = b[i], r = c[i];
		ll res = (pf[r] - pf[l]) * a[i];
		if (mx < res) {
			mx = res;
		}
	}
	cout << "smart O(N) solution constraints up to 1e7  : " << mx << endl;
	cout << "stupid O(N ^ 3) solution up to 1e2         : " << stupid(a) << endl;
	return 0;
}
