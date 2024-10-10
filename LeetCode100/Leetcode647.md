# [647. 回文子串](https://leetcode.cn/problems/palindromic-substrings/?envType=problem-list-v2&envId=2cktkvj)  
## 题解  
`最简单的递归思想`
```cpp  
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                // 极限情况
                if (j == i+1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                }

                if (dp[i][j]) {
                    ++ans;
                }
            }
        }

        return ans + n;
    }
};
```