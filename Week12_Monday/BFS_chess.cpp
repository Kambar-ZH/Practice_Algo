#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int MOD = 1e9 + 7;

int dx[8] = {-2, -2, -1, -1, 1,  1, 2,  2};
int dy[8] = { 1, -1,  2, -2, 2, -2, 1, -1};

bool inbound(pii current, int n) {
    return 0 <= current.first && current.first < n && 0 <= current.second && current.second < n;
}

int main()
{   
    int n; cin >> n;
    pii start; cin >> start.first >> start.second;
    pii target; cin >> target.first >> target.second;
    start.first--, start.second--;
    target.first--, target.second--;
    queue<pii> q;
    q.push(start);
    vt<vt<bool> > used(n, vt<bool> (n, false));
    used[start.first][start.second] = true;
    vt<vt<pii> > parent(n, vt<pii> (n, {-1, -1})); 
    while (!q.empty()) {
        pii current = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            pii neighbour = {current.first + dx[i], current.second + dy[i]};
            if (inbound(neighbour, n) && !used[neighbour.first][neighbour.second]) {
                used[neighbour.first][neighbour.second] = true;
                parent[neighbour.first][neighbour.second] = current;
                q.push(neighbour);
            }
        }
    }
    vt<pii> answer;
    while (target != (pii){-1, -1}) {
        answer.push_back(target);
        target = parent[target.first][target.second];
    }
    cout << answer.size() - 1 << endl;
    reverse(answer.begin(), answer.end());
    for (pii vertex : answer) {
        cout << vertex.first + 1 << " " << vertex.second + 1 << endl;
    }
    return 0;
}