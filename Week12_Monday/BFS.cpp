#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int MOD = 1e9 + 7;

int main()
{
    int n, m; cin >> n >> m;
    // неориентированный
    vt<vt<int> > g(n);
    For(i, m) {
        int v, u; cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        // обратное ребро
        g[u].push_back(v);
    }
    int start, target; cin >> start >> target;
    start--, target--;
    queue<int> q;
    q.push(start);
    vt<bool> used(n);
    vt<int> dist(n);
    used[start] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int neighbour : g[current]) {
            if (!used[neighbour]) {
                used[neighbour] = 1;
                dist[neighbour] = dist[current] + 1;
                q.push(neighbour);
            }
        }
    }
    cout << dist[target] << endl;
    return 0;
}