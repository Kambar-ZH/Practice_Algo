#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int MOD = 1e9 + 7;

const int N = 1e3;
vt<int> used(N);
vt<vt<int> > g(N);
vt<int> order;
bool isBad = false; 

void top_sort(int v) {
    used[v] = 1;
    for (int u : g[v]) {
        if (used[u] == 1) {
            isBad = true;
            return;
        } else if (used[u] == 2) {
            continue;
        }
        top_sort(u);
    }
    order.push_back(v);
    used[v] = 2;
}

int main()
{
    int n, m; cin >> n >> m;

    For(i, m) {
        int v, u; cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (!used[i]) {
            top_sort(i);
        }
    }
    if (isBad) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    vt<bool> used(n);
    reverse(order.begin(), order.end());
    for (int x : order) {
        cout << x + 1 << " ";
    }
    cout << endl;
    return 0;
}