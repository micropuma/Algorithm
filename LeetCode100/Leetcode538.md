# [538. 把二叉搜索树转换为累加树](https://leetcode.cn/problems/convert-bst-to-greater-tree/description/?envType=problem-list-v2&envId=2cktkvj)   
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
private:  
    int s = 0;

    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        } else {
            dfs(root->right);
            s += root->val;
            root->val = s;
            dfs(root->left);
        }
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }   
};
```