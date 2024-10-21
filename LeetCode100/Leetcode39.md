# [组合之和](https://leetcode.cn/problems/combination-sum/solutions/2363929/39-zu-he-zong-he-hui-su-qing-xi-tu-jie-b-9zx7/?envType=problem-list-v2&envId=2cktkvj)  
## 意义  
> 学习最经典的回溯法+剪枝的写法  

```cpp    
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end(), std::less<int>());

        vector<int> state;
        int start = 0;
        vector<vector<int>> result;

        backtrace(target, candidates, result, state, start);
        return result;
    }

private:  
    void backtrace(int target, vector<int>& candidates, vector<vector<int>>& result, vector<int>& state, int start) {
        if (target == 0) {
            result.push_back(state);
            return;
        }

        int sz = candidates.size();
        for (int i = start; i < sz; i++) {
            if (target < candidates[i]) {
                return;
            } else {
                state.push_back(candidates[i]);
                backtrace(target-candidates[i], candidates, result, state, i);
                state.pop_back();
            }
        }
    }
};
```