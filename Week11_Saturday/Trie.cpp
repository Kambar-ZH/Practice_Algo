#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define For(i, n) for (int i = 0; i < n; ++i)
#define pii pair<int, int>

const int MOD = 1e9 + 7;

const int alph = 10;
const int N = 5e5;
int vn = 1;
int to[alph][N];
vt<int> cnt(N);
vt<string> city(N);

void add(string s, string t, int m)
{
    int n = s.length();
    int v = 1;
    int last = -1;
    for (int i = 0; i < n; i++)
    {
        int c = s[i] - '0';
        if (to[c][v] == 0)
        {
            to[c][v] = ++vn;
        }
        if (city[v] != "") {
            last = v;
        }
        v = to[c][v];
    }
    cnt[v] += pow(10, m - s.length());
    city[v] = t;
    cnt[last] -= cnt[v];
}

int main()
{
    int n, m;
    cin >> n >> m;
    For(i, n)
    {
        string s, t;
        cin >> s >> t;
        add(s, t, m);
    }
    for (int i = 0; i <= vn; i++)
    {
        if (city[i] != "")
        {
            cout << city[i] << " " << cnt[i] << endl;
        }
    }
    return 0;
}