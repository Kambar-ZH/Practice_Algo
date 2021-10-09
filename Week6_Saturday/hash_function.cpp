#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int p = 31;
const int N = 2e5;
vt<ll> power(N, 1);

void get_power() {
	for (int i = 1; i < N; ++i) {
		power[i] = power[i - 1] * p;
	}
}

vt<ll> get_hash(string & s, int n) {
	vt<ll> hash(n);
	hash[0] = (s[0] - 'a' + 1);
	For(i, n) {
		if (i > 0) {
			hash[i] = hash[i - 1] + (s[i] - 'a' + 1) * power[i];
		}
	}
	return hash;
}

int main()
{	
	string s, t;
	cin >> t >> s;
	s += s;
	get_power();
	int n = s.length(), m = t.length();
	vt<ll> hash1 = get_hash(s, n), hash2 = get_hash(t, m);
	for (int i = 0; i <= n - m; ++i) {
		ll p = power[i];
		ll res = hash1[i + m - 1];
		if (i > 0) res -= hash1[i - 1]; 
		if (res == hash2[m - 1] * p ) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}