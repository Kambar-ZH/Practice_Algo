#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int MOD = 1e9 + 7;

const int N = 2e5;
vt<int> p(N);
vt<int> r(N);

int get(int u) {
    if (u == p[u]) {
        return u;
    }
    return p[u] = get(p[u]);
}

void merge(int u, int v) {
    if (r[u] == r[v]) {
        r[u]++;
    }
    if (r[u] > r[v]) {
        p[v] = p[u];
        r[v]++;
    } else {
        p[u] = p[v];
        r[u]++;
    }
}

int main()
{
    int n, m; cin >> n >> m;
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> >>, greater<pair<int, pair<int, int> >>> pq;
    For(i, m) {
        int u, v, c; cin >> u >> v >> c; u--, v--;
        pq.push({c, {u, v}});
        pq.push({c, {v, u}});
    }
    For(i, n) {
        p[i] = i;
    }
    int totalCost = 0;
    while (!pq.empty()) {
        auto edge = pq.top();
        pq.pop();
        int u = edge.second.first;
        int v = edge.second.second;
        int cost = edge.first;
        if (get(u) != get(v)) {
            cout << "! " << u + 1 << " " << v + 1 << " " << cost << endl;
            totalCost += cost;
            merge(u, v);
        }
    }
    cout << totalCost << endl;
    return 0;
}