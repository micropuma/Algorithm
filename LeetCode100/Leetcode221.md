# [221. 最大正方形](https://leetcode.cn/problems/maximal-square/description/?envType=problem-list-v2&envId=2cktkvj)
## 题解 
> 重点是想清楚，dp[i][j]表示以i，j为右下角的最大正方形
```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int size1 = matrix.size();
        int size2 = matrix[0].size();
        vector<vector<int>> dp(size1, vector<int>(size2,0));

        int maxSide = 0;

        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                if (matrix[i][j] == '1') {
                    if (i==0 || j== 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                    }
                } 

                maxSide = max(maxSide, dp[i][j]);
            }
        }

        return maxSide * maxSide;
    }
};
```