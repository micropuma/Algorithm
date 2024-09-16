#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int main() {
    // m是总人数， n是窗口
    int m, n;
    int data;
    cin >> m >> n;

    int a[N];

    // q and p store the priority of the seq!
    deque<int> q;
    deque<int> p;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        while (!q.empty() && a[q.back()] > a[i]) {
            q.pop_back();
        }

        q.push_back(i);

        // out of range
        if (i >= n-1) {
            while (!q.empty() && q.front() <= i-n) {
                q.pop_front();
            }
            cout << a[q.front()] << " ";
        }
    }

    cout << '\n';

    for (int i = 0; i < m; i++) {
        while (!p.empty() && a[p.back()] < a[i]) {
            p.pop_back();
        }

        p.push_back(i);

        // out of range
        if (i >= n-1) {
            while (!p.empty() && p.front() <= i-n) {
                p.pop_front();
            }
            cout << a[p.front()] << " ";
        }
    }

    return 0;
}