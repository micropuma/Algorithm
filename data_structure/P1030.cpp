#include <bits/stdc++.h>
using namespace std;


string getPreorder(string& in_order, string& post_order) {
    if (post_order.empty() || in_order.empty()) {
        return "";
    }
    else {
        char root = post_order.back();
        int index = in_order.find(root);
        string left_in_order = in_order.substr(0, index); 
        string right_in_order = in_order.substr(index+1); 
        string left_post_order = post_order.substr(0, index); 
        string right_post_order = post_order.substr(index, post_order.size() - index - 1); 

        return root + getPreorder(left_in_order, left_post_order) + getPreorder(right_in_order, right_post_order); 
    }
}

int main() {
    string in_order, post_order;
    cin >> in_order >> post_order;

    cout << getPreorder(in_order, post_order);

    // cout << in_order << "\n";
    // cout << post_order;

    return 0;
}