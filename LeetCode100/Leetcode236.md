# [236. 二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/?envType=problem-list-v2&envId=2cktkvj)  
## 解答 
> 此题目相比传统的LCA，有一个限定条件：两个节点一定存在于树中。
`解法一：存储父节点哈希，即朴素求法` 
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, TreeNode*> fa;
    unordered_map<int, bool> visited;

    // 用dfs遍历得到父节点哈希存储
    void dfs(TreeNode* root) {
        if (root->left != nullptr) {
            fa[root->left->val] = root;
            dfs(root->left);
        } if (root->right != nullptr) {
            fa[root->right->val] = root;
            dfs(root->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root->val] = nullptr;
        dfs(root);

        // 先从p节点向上跳跃
        while (p != nullptr) {
            visited[p->val] = true;
            p = fa[p->val];
        }

        // 再从q节点向上跳跃  
        while (q != nullptr) {
            if (visited[q->val]) 
                return q;
            else {
                q = fa[q->val];
            }
        }

        return nullptr;
    }
};
```  

`递归解法`
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isInTree(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return false;
        }
        if (root == p || root == q) {
            return true;
        }

        return isInTree(root->left, p, q) || isInTree(root->right, p, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q) {
            return root;
        }
        if (isInTree(root->left,p,q) && isInTree(root->right,p,q)) {
            return root;
        }
        if (!isInTree(root->left,p,q)) 
            return lowestCommonAncestor(root->right, p, q);
        return lowestCommonAncestor(root->left, p, q);
    }
};

> 此题目这个解法比较慢，且比较trickey。两个函数是不同层级的递归。isInTree()是判断p/q是否又在root下的。结合特殊LCA，可以解答本题目。
```

`倍增法`
```cpp

```