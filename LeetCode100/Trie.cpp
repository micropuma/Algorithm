#include <iostream>
#include <unordered_map>

using namespace std;

class Trie {
private:
    bool isEnd;
    unordered_map<char, Trie*> next;

    auto delStr(Trie* root, string s, int depth) -> bool{
        if (root == nullptr) {
            return false;
        }

        if (depth == s.size()) {
            if (!root->isEnd) {
                return false;
            } else {
                root->isEnd = false;
                return root->next.empty();
            }
        }

        char c = s[depth];
        cout << "==" << c << "==\n";
        // 删除成功，决定是否要删除当前节点
        if (delStr(root->next[c], s, depth+1)) {
            delete(root->next[c]);
            root->next.erase(c);
        }

        return root->next.empty() && !root->isEnd;
    }

public:  
    Trie() : isEnd(false) {}

    void insert(string s) {
        Trie* root = this;
        for (char c : s) {
            if (root->next.find(c) == root->next.end()) {
                root->next[c] = new Trie;
            }

            root = root->next[c];
        }

        root->isEnd = true;
    }

    auto search(string s) -> bool{
        Trie* root = this;

        for (char c : s) {
            if (root->next.find(c) == root->next.end()) {
                return false;
            } 

            root = root->next[c];
        }

        return root->isEnd;
    }

    auto searchPrefix(string s) -> bool{
        Trie* root = this;

        for (char c : s) {
            if (root->next.find(c) == root->next.end()) {
                return false;
            } 

            root = root->next[c];
        }

        return true;
    }

    void del(string s) {
        Trie* root = this;

        delStr(this, s, 0);
    }
};

int main() {
    Trie* root = new Trie();
    root->insert("leondou");

    cout << root->search("leondou") << endl;
    cout << root->searchPrefix("eon") << endl;
    cout << root->searchPrefix("leo") << endl; 

    root->del("leondou");
    cout << root->search("leondou");

    return 0;
}