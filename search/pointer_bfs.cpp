#include <bits/stdc++.h>
using namespace std;

// a struct that represents a node
struct Node {
    char value_;
    Node* l_node_;
    Node* r_node_;

    Node(char value = '#', Node *l_node = NULL, Node *r_node = NULL) 
        : value_(value), l_node_(l_node), r_node_(r_node) {}
};

// be careful with the delete operation!
void removeTree(Node* root) {
    if (root == NULL) {
        return;
    } else {
        removeTree(root->l_node_);
        removeTree(root->r_node_);
    }
}

int main() {
    Node *A, *B, *C, *D, *E, *F, *G, *H, *I;
    A = new Node('A');
    B = new Node('B');
    C = new Node('C');
    D = new Node('D');
    E = new Node('E');
    F = new Node('F');
    G = new Node('G'); 
    H = new Node('H');
    I = new Node('I');
    E->l_node_ = B;
    E->r_node_ = G;
    B->l_node_ = A;
    B->r_node_ = D;
    G->l_node_ = F;
    G->r_node_ = I;
    D->l_node_ = C;
    I->l_node_ = H;
    queue<Node> q;
    q.push(*E);
    while(q.size()) {
        Node *tmp;
        tmp = &q.front();
        cout << tmp->value_ << " ";
        q.pop();
        if(tmp->l_node_) {
            q.push(*tmp->l_node_);
        } 
        if (tmp->r_node_) {
            q.push(*tmp->r_node_);
        }
    }
    
    removeTree(E);
    return 0; 
}

