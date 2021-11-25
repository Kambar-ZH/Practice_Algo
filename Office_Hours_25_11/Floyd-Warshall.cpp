#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int MAX = 1e9 + 7;

int main()
{
	int n, s, f; cin >> n >> s >> f; s--, f--;
	vt<vt<int> > a(n, vt<int> (n));
	For(i, n) For(j, n) {
		cin >> a[i][j];
		if (a[i][j] == -1) {
			a[i][j] = MAX;
		}
	}
	For(k, n) For(i, n) For(j, n) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	if (a[s][f] >= MAX) cout << -1 << endl;
	else cout << a[s][f] << endl;
	return 0;
}