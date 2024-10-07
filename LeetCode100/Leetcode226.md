# [226. 翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/?envType=problem-list-v2&envId=2cktkvj)  
## 思路  
* 用递归的想法来做

## 代码  
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }  

        TreeNode* newLeft;
        TreeNode* newRight;

        newLeft = invertTree(root->left);
        newRight = invertTree(root->right);

        root->right = newLeft;
        root->left = newRight;

        return root;
    }
};
```