#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

struct Node {
    char value;
    int lson, rson;
} tree[N];

int i = 1;
int newNode(char val) {
    tree[i].value = val;  // 修正了此处，将 value 改为 val
    tree[i].lson = 0;
    tree[i].rson = 0;
    return i++;
}

void Insert(int &father, int child, int l_r) {
    if (l_r == 0) {
        tree[father].lson = child;
    } else {
        tree[father].rson = child;
    }
}

int buildTree() {
    int A = newNode('A');
    int B = newNode('B');
    int C = newNode('C');
    int D = newNode('D');
    int E = newNode('E');
    int F = newNode('F');
    int G = newNode('G');
    int H = newNode('H');
    int I = newNode('I');
    Insert(E,B,0);
    Insert(E,G,1);
    Insert(B,A,0);
    Insert(B,D,1);
    Insert(G,F,0);
    Insert(G,I,1);
    Insert(D,C,0);
    Insert(I,H,0);
    int root = E;
    return root;
}

int main() {
    int root = buildTree();
    queue<int> q;
    q.push(root);
    while (q.size()) {
        int temp = q.front();
        cout << tree[temp].value << " ";
        q.pop();
        if (tree[temp].lson != 0) q.push(tree[temp].lson);
        if (tree[temp].rson != 0) q.push(tree[temp].rson);
    }

    return 0;
}