```cpp   
class Solution {
public:
    int minDistance(string word1, string word2) {
        int sz1 = word1.length();
        int sz2 = word2.length();

        vector<vector<int>> dp(sz1+1, vector<int>(sz2+1, 0));

        for (int i = 0; i < sz1; i++) {
            dp[i][sz2] = sz1 - i;
        }

        for (int i = 0; i < sz2; i++) {
            dp[sz1][i] = sz2 - i;
        }

        for (int i = sz1-1; i >= 0; i--) {
            for (int j = sz2-1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    int temp;
                    temp = min(1 + dp[i+1][j], 1 + dp[i][j+1]);
                    dp[i][j] = min(1 + dp[i+1][j+1], temp);
                }
            }
        }

        return dp[0][0];
    }
};
```