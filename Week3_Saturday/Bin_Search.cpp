#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb(i)               push_back(i)
#define For(i, n)           for(int i = 0; i < n; ++i)

int main()
{
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        int left = 0, right = n - 1, middle;
        // cout << "start to search " << b[i] << endl;
        while (left < right) {
            int middle = (left + right) / 2;
            // cout << left << " " << middle << " " << right << endl;
            if (a[middle] < b[i]) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }   
        if (a[left] == b[i]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } 
    return 0;
}