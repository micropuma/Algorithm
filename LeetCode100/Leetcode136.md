# [136. 只出现一次的数字](https://leetcode.cn/problems/single-number/description/?envType=problem-list-v2&envId=2cktkvj)  
## 代码  
```cpp 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (auto num : nums) {
            result = result ^ num;
        }

        return result;
    }
};
```