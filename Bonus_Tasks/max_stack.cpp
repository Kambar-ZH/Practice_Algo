#include <bits/stdc++.h>
using namespace std;

#define For(i, n)           for(int i = 0; i < n; ++i)
#define see                 cout << endl;
#define vt		    vector

int main()
{
	
	clock_t start = clock();
	int n, k; cin >> n >> k;
	vt<int> a(n); 
	For(i, n) {
		a[i] = rand() % 100 + 10;
	}
	print(a);
	deque<int> dq;
	For(i, k - 1) {
		while (!dq.empty() && a[dq.back()] <= a[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
	}
	for (int i = k - 1; i < n; ++i) {
		while (!dq.empty() && a[dq.back()] <= a[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
		while (dq.back() - dq.front() >= k) {
			dq.pop_front();
		}
		cout << a[dq.front()] << " ";
	}
	see;
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time: %f seconds\n", seconds);
	return 0;
}
