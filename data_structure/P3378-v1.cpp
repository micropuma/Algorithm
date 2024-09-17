#include <bits/stdc++.h>
using namespace std;

// 用stl库，解决P3378问题。

int main() {
    priority_queue<int, vector<int>, greater<int>> queue;
    int n, op, num;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> op;
        switch(op) {
            case 1:
                cin >> num;
                queue.push(num);
                break;
            case 2:
                cout << queue.top() << "\n";
                break;
            case 3:
                queue.pop(); 
                break;
        }
    }
    
    return 0;
}