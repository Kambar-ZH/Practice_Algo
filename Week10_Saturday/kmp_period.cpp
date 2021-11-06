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

int main()
{
    string s; cin >> s;
    int n = s.length();
    auto res = KMP(s);
    int t = n - res[n - 1];
    // for (int x : res) {
    //     cout << x << " ";
    // }
    // cout << endl;
    if (n % t != 0) {
        cout << 1 << endl;
    } else {
        cout << n / t << endl; 
    }
    return 0;
}