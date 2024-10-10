# [543. 二叉树的直径](https://leetcode.cn/problems/diameter-of-binary-tree/?envType=problem-list-v2&envId=2cktkvj)  
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
    int depth(TreeNode* root) {
        if(root == NULL) {
            return -1;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        return max(left, right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int ans = max(diameterOfBinaryTree(root->right), 
                   diameterOfBinaryTree(root->left));
        ans = max(ans, depth(root->left) + depth(root->right) + 2);
        return ans;
    }
};
```

`更优解`
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
    int ans = 0;

    int depth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        ans = max(ans, left + right + 1);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans-1;
    }
};
```

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
    int depth(TreeNode* root, int& ans) {
        if(root == NULL) {
            return 0;
        }
        int left = depth(root->left, ans);
        int right = depth(root->right, ans);
        ans = max(ans, left + right + 1);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        depth(root, ans);
        return ans-1;
    }
};
```