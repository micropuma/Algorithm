# [121. 买股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/?envType=problem-list-v2&envId=2cktkvj)  
## 题解
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = 1e9;
        int maxprofit = 0;

        for (int price : prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }

        return maxprofit;
    }
};
```