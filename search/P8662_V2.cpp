#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
char island[N][N];
bool flooded = true;
int n;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    island[x][y] = '*'; // 标记已经访问
    
    int dx[] = {0, 0, 1, -1}; // 分别代表左右上下的移动
    int dy[] = {1, -1, 0, 0};
    
    while (!q.empty()) {
        auto [x1, x2] = q.front();
        q.pop();
        island[x1][x2] = '*'; // 标记访问

        bool failed = true;
        for (int i = 0; i < 4; i++) {
            int nx = x1 + dx[i];
            int ny = x2 + dy[i];
            if (island[nx][ny] == '.') {
                failed = false;
                break;
            }
        }

        if (failed) {
            flooded = false;
        }
        
        // 扩展到四周未访问的区域
        for (int i = 0; i < 4; i++) {
            int nx = x1 + dx[i];
            int ny = x2 + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && island[nx][ny] == '#') {
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> island[i];
    } 

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (island[i][j] == '#') {
                flooded = true; // 初始化为 flooded，bfs中会修改
                bfs(i, j);
                if (flooded) {
                    ans++;
                }
            }
        }
    }

    cout << ans;

    return 0;
}
