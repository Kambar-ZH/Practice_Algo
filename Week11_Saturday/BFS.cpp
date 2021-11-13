#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int MOD = 1e9 + 7;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool inbound(int i, int j, int n, int m) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vt<vt<char> > lab(n, vt<char> (m));
    For(i, n) For(j, m) cin >> lab[i][j];
    int Q; cin >> Q;
    for (int qq = 0; qq < Q; qq++) {
        int a, b; cin >> a >> b; a--, b--;
        int c, d; cin >> c >> d; c--, d--;
        if (lab[a][b] == '#') {
            cout << "Invalid starting pos" << endl;
            continue;
        }
        queue<pii> q;
        q.push({a, b});
        vt<vt<int> > used(n, vt<int> (m));
        used[a][b] = 1;
        while (!q.empty()) {
            pii v = q.front();
            q.pop();
            int i = v.first;
            int j = v.second;
            for (int z = 0; z < 4; z++) {
                int new_i = i + dx[z];
                int new_j = j + dy[z];
                if (inbound(new_i, new_j, n, m) && used[new_i][new_j] == 0 && lab[new_i][new_j] != '#') {
                    used[new_i][new_j] = 1;
                    q.push({new_i, new_j});
                }
            }
        }
        if (used[c][d]) {
            cout << "Found path!" << endl;
        } else {
            cout << "Can't find path" << endl;
        }
    }
    return 0;
}