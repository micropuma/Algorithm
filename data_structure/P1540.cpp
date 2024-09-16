#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;

    cin >> m >> n;

    queue<int> q;
    int Hash[1002] = {0};
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int word;
        cin >> word;
        if (Hash[word] == 0) {
            Hash[word] = 1;
            cnt ++;
            q.push(word);
        }

        int num;
        if (q.size() > m) {
            num = q.front();
            q.pop();
            Hash[num] = 0;
        }
    }

    cout << cnt << endl;
    return 0;
}