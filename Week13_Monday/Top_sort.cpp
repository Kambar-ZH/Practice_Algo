#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<int, int>

const int MOD = 1e9 + 7;

const int N = 1e3;
vt<int> state(N);
vt<vt<int> > g(N);
vt<int> order;
bool isCyclic = false; 

void top_sort(int current) {
	state[current] = 1;
	for (int neighbour : g[current]) {
		if (state[neighbour] == 1) {
			isCyclic = true;
			return;
		} else if (state[neighbour] == 2) {
			continue;
		}
		top_sort(neighbour);
	}
	state[current] = 2;
	order.push_back(current);
}

int main()
{
	int n, m; cin >> n >> m;

    For(i, m) {
        int v, u; cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (state[i] == 0) {
            top_sort(i);
        }
    }
	if (isCyclic) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	reverse(order.begin(), order.end());
	for (int vertex : order) {
		cout << vertex + 1 << " ";
	}
	cout << endl;
	return 0;
}