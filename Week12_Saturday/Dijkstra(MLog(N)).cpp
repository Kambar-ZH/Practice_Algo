#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vt<vt<pii> > g(n);
    For(i, m) {
        int v, u, c; cin >> v >> u >> c;
        g[v].push_back({u, c});
        g[u].push_back({v, c});
    }
    int s; cin >> s;
    vt<int> d(n, 2009000999);
    priority_queue<pii, vt<pii>, greater<pii> > pq;
    pq.push({0, s});
    d[s] = 0;
    while (!pq.empty()) {
        pii v = pq.top();
        pq.pop();
        if (v.first > d[v.second]) {
            continue;
        }
        for (pii u : g[v.second]) {
            if (d[u.first] > v.first + u.second) {
                d[u.first] = v.first + u.second;
                pq.push({d[u.first], u.first});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
}

int main()
{
    int T; cin >> T;
    For(t, T) {
        solve();
    }
    return 0;
}