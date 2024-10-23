# [494. 目标和](https://leetcode.cn/problems/target-sum/?envType=problem-list-v2&envId=2cktkvj)
## 解答  
```cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalNum = 0;
        int start = 0;
        int sz = nums.size();

        vector<int> prefix_sum(sz+1, 0);

        for (int i = sz-1; i >= 0; i--) {
            prefix_sum[i] = prefix_sum[i+1] + nums[i];
        }  

        for (const auto num: prefix_sum) {
            cout << num << " ";
        }
        cout << "\n";

        return backtrack(start, totalNum, target, nums, prefix_sum);
    }

private:  
    int backtrack(int start, int totalNum, int target, vector<int>& nums, vector<int>& prefix_sum) {
        int sz = nums.size();
        if (start == sz) {
            if (totalNum == target) {
                return 1;
            } else {
                return 0;
            }
        }
        
        // 剪枝  
        if (totalNum + prefix_sum[start] < target || totalNum - prefix_sum[start] > target) {
            return 0;
        } else {
            return backtrack(start+1, totalNum + nums[start], target, nums, prefix_sum) + 
                   backtrack(start+1, totalNum - nums[start], target, nums, prefix_sum);
        }
    }
};
```
> 此方案用的是回溯法+剪枝，问题是，时间复杂度过于慢了。  

下面是用背包解决：[背包解法](https://leetcode.cn/problems/target-sum/solutions/816361/mu-biao-he-by-leetcode-solution-o0cp/?envType=problem-list-v2&envId=2cktkvj)
```cpp   
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {  
        int sz = nums.size();

        // (sum - neg) - neg = target
        int sum = 0;
        for (const auto num : nums) {
            sum += num;
        }

        int diff = sum - target;

        if(diff < 0 || diff %2 == 1) {
            return 0;
        }  

        diff /= 2;

        vector<vector<int>> dp(sz+1, vector<int>(diff+1,0));
        dp[0][0] = 1;

        for (int i = 1; i <= sz; i++) {
            // j必须从0开始，trickey。
            for (int j = 0; j <= diff; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i-1]) {
                    dp[i][j] += dp[i-1][j-nums[i-1]];
                }
            }
        }  

        return dp[sz][diff];
    }
};
```   

`滚动dp`    
> dp相当于一个状态机，i这个状态其实是没有的，因为i只依赖于i-1。所以可以用滚动dp降空间。 
```cpp   
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {  
        int sz = nums.size();

        // (sum - neg) - neg = target
        int sum = 0;
        for (const auto num : nums) {
            sum += num;
        }

        int diff = sum - target;

        if(diff < 0 || diff %2 == 1) {
            return 0;
        }  

        diff /= 2;

        vector<int> dp(vector<int>(diff+1,0));
        dp[0] = 1;

        for (int& num : nums) {
            for (int j = diff; j >= num; j--) {
                dp[j] += dp[j-num];
            }
        } 

        return dp[diff];
    }
};
```