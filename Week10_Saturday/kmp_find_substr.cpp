#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int MOD = 1e9 + 7;

vt<int> KMP(string s) {
    int n = s.length();
    vt<int> p(n);
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
    }
    return p;
}

void Solve()
{
    string s, t; cin >> s >> t;
    auto res = KMP(t + "#" + s);
    int m = t.length();

    // ab#ababab
    // 000121212 
    // 123456789

    vt<int> ans;
    for (int i = 0; i < res.size(); i++) {
        int x = res[i];
        if (x == m) {
            ans.push_back(i + 1 - m - 1 - m + 1);
        }
    }
    if (ans.empty()) {
        cout << "Not Found" << '\n';
        cout << '\n';
        return;
    }
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << " ";
    }
    cout << '\n';
    cout << '\n';
}

int main() {
    int T; cin >> T;
    For(t, T) {
        Solve();
    }
}