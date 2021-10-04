#include <bits/stdc++.h>
using namespace std;

#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)

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
    write();
    return 0;
}
