#include <bits/stdc++.h>
using namespace std;

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
    write();
    return 0;
}
