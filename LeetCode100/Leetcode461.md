# [461. 汉明距离](https://leetcode.cn/problems/hamming-distance/?envType=problem-list-v2&envId=2cktkvj)
## 题解  
```cpp  
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int ret = 0;

        while (z > 0) {
            ret += z & 1;
            z >>= 1;
        }

        return ret;
    }
};
```

`巧妙解法！！！`
```cpp 
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int ret = 0;

        while (z > 0) {
            z = z & z-1;
            ret++;
        }

        return ret;
    }
}; 
```
