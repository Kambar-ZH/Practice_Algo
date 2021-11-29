#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int MOD = 1e9 + 7;
const int MAX = 2009000999;

const int N = 2e5;
vt<vt<pii> > g(N);
int n, m;

pair<int, vt<int> > Dijkstra(int s, int f) {
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
            // min_time[cur.from] <= cur.time_to_start && min_time[cur.to] > cur.time_to_end {
            //     min_time[cur.to] = cur.time_to_end;
            // } 
			if (dist[neighbour.first] > cur.first + neighbour.second) {
				dist[neighbour.first] = cur.first + neighbour.second;
				pq.push({dist[neighbour.first], neighbour.first});
			}
		}
	}
    vt<int> path {f};
    int temp_f = f;
    while (dist[temp_f] != 0) {
        for (pii neighbour : g[temp_f]) {
            if (dist[neighbour.first] + neighbour.second == dist[temp_f]) {
                temp_f = neighbour.first;
                path.push_back(temp_f);
                break;
            }
        }
    }
    reverse(path.begin(), path.end());
	return {dist[f], path};
}

int main()
{
	cin >> n >> m;
    For(i, m) {
        int v, u, c; cin >> v >> u >> c;
        g[v].push_back({u, c});
        g[u].push_back({v, c});
    }
    int s, i, f; cin >> s >> i >> f;
    auto res1 = Dijkstra(s, i);
    auto res2 = Dijkstra(i, f);
    int total_dist = res1.first + res2.first;
    vt<int> total_path;
    for (int v : res1.second) {
        total_path.push_back(v);
    }
    for (int i = 1; i < res2.second.size(); i++) {
        total_path.push_back(res2.second[i]);
    }
    cout << total_dist << endl;
    for (int v : total_path) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}