# [739. 每日温度](https://leetcode.cn/problems/daily-temperatures/description/?envType=problem-list-v2&envId=2cktkvj)  
## 题解 
`单调栈` 
```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        deque<int> q;
        int sz = temperatures.size();
        vector<int> result(sz, 0);

        for (int i = 0; i < sz; i++) {
            if (q.empty() || temperatures[q.back()] >= temperatures[i]) {
                q.push_back(i);
            } else {
                while (!q.empty() && temperatures[q.back()] < temperatures[i]) {
                    int index = q.back();
                    q.pop_back();
                    result[index] = i - index;
                }
                q.push_back(i);
            }
        }

        return result;
    }
};
```

> 本题是单调栈的经典题目