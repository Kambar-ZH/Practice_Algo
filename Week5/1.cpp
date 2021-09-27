#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb(i)               push_back(i)
#define For(i, n)           for(int i = 0; i < n; ++i)

int leftbound(vector<int> & a, int target) {
    int n = a.size();
    int l = 0, r = n - 1, m; 
    while (l < r) {
        int m = (l + r) / 2;
        if (a[m] < target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

int rightbound(vector<int> & a, int target) {
    int n = a.size();
    int l = 0, r = n - 1, m; 
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (a[m] <= target) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    return l;
}

int main()
{
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    For(i, n) cin >> a[i];
    For(i, m) cin >> b[i];
    for (int i = 0; i < m; ++i) {
        int target = b[i];
        int left = leftbound(a, target), right = rightbound(a, target);
        if (a[left] == target) {
            cout << left + 1 << " " << right + 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}