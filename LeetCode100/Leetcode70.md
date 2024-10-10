# [70. 使用最小费用爬楼梯](https://leetcode.cn/problems/climbing-stairs/submissions/571628157/?envType=problem-list-v2&envId=2cktkvj)  
## 题解 
```cpp
class Solution {
public:

    int climbStairs(int n) {
        int p = 1;
        int q = 2;
        int r = 0;

        if ( n ==1 ) {
            return p;
        } else if ( n==2 ) {
            return q;
        } else {
            for (int i = 3; i <= n; i++) {
                r = p + q;
                p = q;
                q = r;
            }
        }

        return r;
    }
};
```