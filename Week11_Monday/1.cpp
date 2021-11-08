#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int MOD = 1e9 + 7;
const int p = 31;

int main()
{
    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();
    int hash[n + 1];
    hash[0] = 0;
    int power[n + 1];
    power[1] = 1;
    for (int i = 1; i <= n; i++) {
        hash[i] = hash[i - 1] + power[i] * (s[i - 1] - 'a' + 1);
        power[i + 1] = power[i] * p;
    }
    int hash_t = 0;
    for (int i = 1; i <= m; i++) {
        hash_t += power[i] * (t[i - 1] - 'a' + 1);
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << hash[i] << " ";
    // }
    // cout << endl;
    // cout << hash_t << endl;
    for (int i = m; i <= n; i++) {
        int cur_hash = hash[i] - hash[i - m];
        int target_hash = hash_t * power[i - m + 1];
        // cout << cur_hash << " " << target_hash << endl;
        if (cur_hash == target_hash) {
            cout << i - m + 1 << endl;
        }
    }
    return 0;
}