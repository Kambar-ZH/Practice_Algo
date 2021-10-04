#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb(i)               push_back(i)
#define For(i, n)           for(int i = 0; i < n; ++i)
#define qFor(i, x, n)       for(int i = x; i < n; ++i)
#define rFor(i, n)          for(int i = n - 1; i >= 0; --i)
#define see                 cout << endl;
#define all(x)              (x).begin(),(x).end()
#define rall(x)             (x).rbegin(),(x).rend()
#define ls x + x
#define rs x + x + 1

#define ld                  long double
#define pii                 pair<int, int>
#define vt                  vector
#define ll                  long long
#define ordered_set         tree < pair<pair<int, int>, int>,  null_type ,  less<pair<pair<int, int>, int> > ,  rb_tree_tag ,  tree_order_statistics_node_update >

const int MAX = 1e9;
const int MOD = 1e9 + 7;
const int BINT = 32;
const int BLONG = 64;
const ll  INF = 1e18;
const ld  PI  = 3.14159265358979323846;
 
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

void write()
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
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("out.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	int T;
	T = 1;
	// cin >> T;
	For(t, T) write();
	return 0;
}