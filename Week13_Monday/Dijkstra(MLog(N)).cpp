#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int MAX = 2009000999;

int test() {
	int n, m; cin >> n >> m;
    vt<vt<pii> > g(n);
    For(i, m) {
        int v, u, c; cin >> v >> u >> c;
        g[v].push_back({u, c});
        g[u].push_back({v, c});
    }
	int s; cin >> s;
	vt<int> dist(n, MAX);
	dist[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({dist[s], s});
	while (!pq.empty()) {
		pii cur = pq.top();
		pq.pop();
		if (dist[cur.second] < cur.first) {
			continue;
		}
		for (pii neighbour : g[cur.second]) {
			if (dist[neighbour.first] > cur.first + neighbour.second) {
				dist[neighbour.first] = cur.first + neighbour.second;
				pq.push({dist[neighbour.first], neighbour.first});
			}
		}
	}
	for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
	return 0;
}

int main()
{
	int T; cin >> T;
	For(t, T) {
		test();
	}
	return 0;
}