#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb(i)               push_back(i)
#define For(i, n)           for(int i = 0; i < n; ++i)
#define qFor(i, x, n)       for(int i = x; i < n; ++i)
#define rFor(i, n)          for(int i = n - 1; i >= 0; --i)
#define see                 cout << endl;
#define all(x)              (x).begin(),(x).end()
#define rall(x)             (x).rbegin(),(x).rend()
#define ls x + x
#define rs x + x + 1

#define ld                  long double
#define pii                 pair<int, int>
#define vt                  vector
#define ll                  long long
#define ordered_set         tree < pair<pair<int, int>, int>,  null_type ,  less<pair<pair<int, int>, int> > ,  rb_tree_tag ,  tree_order_statistics_node_update >


const int MAX = 1e9;
const int MOD = 1e9 + 7;
const int BINT = 32;
const int BLONG = 64;
const ll  INF = 1e18;
const ld  PI  = 3.14159265358979323846;
 
template<typename T>
void read(vt<T> & a) {
    For(i, a.size()) cin >> a[i];
}
template<typename T>
void print(vt<T> & a) {
    For(i, a.size()) cout << a[i] << " ";
    cout << endl;
}
template<typename T>
void print2(vt<vt<T> > & a) {
    For(i, a.size()) {
        For(j, a[i].size()) cout << a[i][j] << " ";
        cout << endl;
    }
}
template<typename T>
void read2(vt<vt<T> > & a) {
    For(i, a.size()) For(j, a[i].size()) cin >> a[i][j];
}
void read_pair(vt<pii> & a) {
    For(i, a.size()) cin >> a[i].first >> a[i].second;
}

ll binPow(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 1) {
        return binPow(a, b - 1) * a % MOD;
    }
    ll temp = binPow(a, b / 2);
    return temp * temp % MOD;
}

void write()
{
    int n; cin >> n;

    vt<pair<int, int> > operations;
    vector<stack<int> > st(n);
    bool bad_permutation = false;
    // Считали данные
    For(i, n) {
        int sz; cin >> sz;
        For(j, sz) {
            int x; cin >> x;
            st[i].push(x);
            if (i + 1 != x) { // проверили что есть кривой контейнер
                bad_permutation = true;
            }
        }
    }
    if (bad_permutation == false) {
        return;
    } 
    int start = 0;
    for (int i = 1; i < n; ++i) { 
        while (!st[i].empty()) { // переносим все контейнеры со всех стопок в первую
            int val = st[i].top();
            st[i].pop();
            st[start].push(val);
            operations.push_back(make_pair(i + 1, start + 1));
        }  
    }
    
    if (n == 2) { // когда две стопки
        int temp = 1;
        while (!st[temp].empty()) { // переносим все контейнеры в стопку 1
            int x = st[temp].top();
            st[start].push(x);
            operations.push_back(make_pair(temp + 1, start + 1));
        }
        bool seen = false;
        while (!st[start].empty()) { // из стопки 1 переносим 2 в контейнер 2
            int x = st[start].top(); 
            st[start].pop();
            if (x == 1) { // если встречаем 1ую единичку
                seen = true;
            }
            if (seen && x == 2) { // то за ней не должно встречаться двоек
                cout << 0 << endl;
                return;
            }
            st[temp].push(x);
            operations.push_back(make_pair(start + 1, temp + 1));
        }
        while (!st[temp].empty()) { // из 2 стопки в 1ый пока не встретим двойку
            int x = st[temp].top();
            if (x == temp + 1) {
                break;
            }
            st[temp].pop();
            st[start].push(x);
            operations.push_back(make_pair(temp + 1, start + 1));
        }
    } else {
        int temp = 1;
        while (!st[start].empty()) { // переносим все значение в свои стопки
            int x = st[start].top();
            st[start].pop();
            int idx = x - 1;
            if (x == start + 1) { // если контейнер = 1, переносим в стопку 2
                idx = temp;
            }
            st[idx].push(x);
            operations.push_back(make_pair(start + 1, idx + 1));
        }
        int temp2 = 2;
        while (!st[temp].empty()) { // переносим все значения (1, 2) с контейнера два на свои места
            int x = st[temp].top(); 
            st[temp].pop();
            int idx = x - 1;
            if (x == 2) { // если встретим 2, переносим в контейнер 3
                idx = temp2;
            }
            st[idx].push(x);
            operations.push_back(make_pair(temp + 1, idx + 1));
        }
        while (!st[temp2].empty()) { // из стопки 3 в стопку 2 
            int x = st[temp2].top();
            if (x == temp2 + 1) { // пока не встретим первую тройку
                break;
            }
            st[temp2].pop();
            st[temp].push(x);
            operations.push_back(make_pair(temp2 + 1, temp + 1));
        }
    }
    for (auto op : operations) {
        cout << op.first << " " << op.second << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int T;
    T = 1;
    For(t, T) write();
    return 0;
}
