# [104. 二叉树的最大深度](https://leetcode.cn/problem-list/2cktkvj/)  
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else {
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
    }
};
```  

`优化的解答`
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
    int maxDepth(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        if (root == nullptr) {
            return 0;
        } else {
            q.push(root);

            while (!q.empty()) {
                int size = q.size();
                while (size > 0) {
                    auto temp = q.front();
                    q.pop();
                    if (temp->left != nullptr) {
                        q.push(temp->left);
                    } 
                    if (temp->right != nullptr) {
                        q.push(temp->right);
                    }
                    size --;
                }

                ans ++;
            }

            return ans;
        }
    }
};
```