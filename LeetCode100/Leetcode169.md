# [169. 多数元素](https://leetcode.cn/problems/majority-element/description/?envType=problem-list-v2&envId=2cktkvj)  
## 题解  
> 重点思想：将数组排序，然后由于大于n/2，所以一定覆盖array[n/2]项。
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
```