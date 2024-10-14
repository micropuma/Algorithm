# [198. 打家劫舍](https://leetcode.cn/problems/house-robber/?envType=problem-list-v2&envId=2cktkvj)
## 题解
```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();

        if (sz == 0) {
            return 0;
        }
        if (sz == 1) {
            return nums[0];
        }

        vector<int> dp(sz, 0);
        // 初始化dp数组 
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < sz ; i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }

        return dp[sz-1];
    }    
};
```