#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int MOD = 1e9 + 7;

int vn = 1;
const int N = 5e5;
const int alphabet = 26;
int to[alphabet][N];
vt<int> cnt(N);

void add(string s) {
	int n = s.length();
	int v = 1;
	For(i, n) {
		int c = s[i] - 'a';
		if (to[v][c] == 0) {
			to[v][c] = ++vn;
		}
		v = to[v][c];
		cnt[v]++;
	}
}

int get_cnt(string s) {
	int n = s.length();
	int v = 1;
	For(i, n) {
		int c = s[i] - 'a';
		if (to[v][c] == 0) {
			return 0;
		}
		v = to[v][c];
	}
	return cnt[v];
}

int main()
{
	int n; cin >> n;
	For (i, n) {
		string s; cin >> s;
		add(s);
	}
	int m; cin >> m;
	For (i, m) {
		string t; cin >> t;
		cout << get_cnt(t) << endl;
	}
	return 0;
}