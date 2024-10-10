# [101. 对称二叉树](https://leetcode.cn/problems/symmetric-tree/?envType=problem-list-v2&envId=2cktkvj)  
## 题解 
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
    bool isTheSame(TreeNode* left, TreeNode* right) {
        if(left == nullptr || right == nullptr)
            return left == nullptr && right == nullptr;
        else {
            return (left->val == right->val)
                && isTheSame(left->left, right->right)
                && isTheSame(left->right, right->left);
        }
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        } 
        return isTheSame(root->left, root->right);
    }
};
```