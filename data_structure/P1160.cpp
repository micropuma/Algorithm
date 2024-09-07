// insert()是插入在前

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    list<int> queue;
    // 维护每个iterator的位置，保证是O(n)的总体时间复杂度。
    map<int, list<int>::iterator> position;
    queue.push_back(1);
    position[1] = queue.begin();

    for (int i = 1; i < n; i++) {
        int stu, pos;
        cin >> stu >> pos;
        auto it = position[stu]; 

        if (pos == 0) {
            auto new_position = queue.insert(it, i+1);
            position[i+1] = new_position;
        } else {
            ++it;
            auto new_position = queue.insert(it, i+1);
            position[i+1] = new_position;
        }
    }

    cin >> m;
    int del;
    for (int i = 0; i < m; i++) {
        cin >> del;
        if (position.find(del) != position.end()) {
            queue.erase(position[del]);
            position.erase(del);
        }
    }

    for (const auto& it : queue) {
        cout << it << " ";
    }

    return 0;
}