# [62. 路径之和](https://leetcode.cn/problems/unique-paths/?envType=problem-list-v2&envId=2cktkvj)
```cpp  
class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));
        dp[m-1][n-1] = 1;

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j --) {
                if (dp[i][j] == 0) {
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }

        return dp[0][0];
    }
};
```