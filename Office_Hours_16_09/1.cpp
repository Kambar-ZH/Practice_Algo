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


const int sz = 2e5;
const int middle = 1e5;
int deq[sz];
int head = middle, tail = middle;

void push_front(int data) {
    deq[head] = data;
    head--;
}

void push_back(int data) {
    tail++;
    deq[tail] = data;
}

void pop_back() {
    tail--;
} 

int back() {
    int val = deq[tail];
    return val;
} 

void pop_front() {
    head++;
}

int front() {
    int val = deq[head + 1];
    return val;
}

bool empty() {
    return tail == head;
}

void clear() {
    head = tail = middle;
}

void write()
{
    
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
    cin >> T;
    For(t, T) write();
    return 0;
}