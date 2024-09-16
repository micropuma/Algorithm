#include <bits/stdc++.h>
using namespace std;

const int N = 100003;

int main() {
    stack<int> s;
    int ans[N];
    int num[N];

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i]; 
    }

    for (int i = n-1; i >= 0; i--) {
        while(!s.empty() && num[s.top()] <= num[i]) {
            s.pop();
        }

        if (s.empty()) {
            ans[i] = 0;
        }
        else {
            ans[i] = s.top();
        }
        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] != 0) {
            ans[i] += 1;
        }
        cout << ans[i] << "\n";
    }

    return 0;
}