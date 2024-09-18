#include <bits/stdc++.h>
using namespace std;

bool flooded = false;
const int N = 1005;
char island[N][N];
int visited[N][N] = {0};

void dfs(int i, int j) {
    visited[i][j] = 1;
    // 判断是否会被淹没
    if (island[i][j+1] == '#' && island[i][j-1] == '#' 
        && island[i-1][j] == '#' && island[i+1][j] == '#') {
            flooded = false;
        }    

    // dfs搜索邻接  
    if (!visited[i][j+1] && island[i][j+1] == '#') {
        dfs(i, j+1);
    }
    if (!visited[i][j-1] && island[i][j-1] == '#') {
        dfs(i, j-1);
    }
    if (!visited[i+1][j] && island[i+1][j] == '#') {
        dfs(i+1, j);
    }
    if (!visited[i-1][j] && island[i-1][j] == '#') {
        dfs(i-1, j);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> island[i]; 
    }

    // for debug
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << island[i][j];
    //     }
    //     cout << "\n";
    // }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 没有访问过，并且是岛
            if(visited[i][j] == 0 && island[i][j] == '#') {
                flooded = true;
                dfs(i, j);
                if (flooded) {
                    ans++;
                }
            }
        }
    }

    cout << ans;

    return 0;
}