# [337. 打家劫舍](https://leetcode.cn/problems/house-robber-iii/?envType=problem-list-v2&envId=2cktkvj)  
> 十分巧妙，学会如何在树上做dp  

```cpp   
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        pair<int, int> count = gain(root);
        return max(count.first, count.second);
    }

private:  
    pair<int, int> gain(TreeNode* root) {
        if (root == nullptr) {
            return make_pair<int, int>(0, 0);
        } else {   
            pair<int, int> left = gain(root->left);
            pair<int, int> right = gain(root->right);  
            return make_pair<int, int>(left.second + right.second + root->val, max(left.first, left.second) + max(right.first,   right.second));
        }
    }
};
```