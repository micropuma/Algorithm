# [437. 路径总和](https://leetcode.cn/problems/path-sum-iii/description/?envType=problem-list-v2&envId=2cktkvj)
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
    int pathSum(TreeNode* root, int targetSum) {  
        if (root == nullptr) {
            return 0;
        } else {
            int ret = rootSum(root, targetSum);
            ret += rootSum(root->left, targetSum);
            ret += rootSum(root->right, targetSum);

            return ret;
        }
    }

private:  
    int rootSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        } else {
            int ret = 0;

            if (root->val == targetSum) {
                ret++;
            }

            ret += rootSum(root->left, targetSum - root->val);
            ret += rootSum(root->right, targetSum - root->val);

            return ret;
        }
    }
};
```