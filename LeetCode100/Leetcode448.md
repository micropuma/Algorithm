# [448. 找到所有数组中消失的数](https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/?envType=problem-list-v2&envId=2cktkvj)  
## 题解  
```cpp  
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        vector<int> vec(n, 0);
        for (const auto num: nums) {
            vec[num-1]++;
        }

        int size = vec.size();
        for (int i = 0; i < size; i++) {
            if (vec[i] == 0) {
                result.push_back(i+1);
            }
        }

        return result;
    }
};
```

`鸽笼原理`
```cpp 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();

        for (auto num : nums) {
            int x = (num-1) % n;
            nums[x] += n;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                result.push_back(i+1);
            }
        }

        return result;
    }
};
```