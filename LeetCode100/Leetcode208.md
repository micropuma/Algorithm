# [208. 实现Trie树](https://leetcode.cn/problems/implement-trie-prefix-tree/description/?envType=problem-list-v2&envId=2cktkvj)  
## 解答  
```cpp
class Trie {
public:
    Trie() {
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* root = this;
        for (char c : word) {
            if (root->children.find(c) == root->children.end()) {
                root->children[c] = new Trie();
            }
            root = root->children[c];
        }

        root->isEnd = true;
    }
    
    bool search(string word) {
        Trie* root = this;

        for (char c: word) {
            if (root->children.find(c) == root->children.end()) {
                return false;
            }

            root = root->children[c];
        }

        return root->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* root = this;

        for (char c: prefix) {
            if (root->children.find(c) == root->children.end()) {
                return false;
            }

            root = root->children[c];
        }

        return true;
    }

private:
    unordered_map<char, Trie*> children;
    bool isEnd;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```

> 用unordered_map实现有点多次一举了。并且，Trie树真正难点在于delete，下面是另一个版本：  

```cpp  

```