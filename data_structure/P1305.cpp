#include <bits/stdc++.h>
using namespace std;

char arr[27][2];

void printInOrder(char root) {
    int index = root - 'a';
    cout << root;
    char left = arr[index][0];
    char right = arr[index][1];

    if (left != '*') {
        printInOrder(left);
    }
    if (right != '*') {
        printInOrder(right);
    }
}

int main() {
    int n;
    cin >> n;
    char root;

    // 初始化
    string input = "";

    for (int i = 0; i < n; i++) {
        cin >> input;
        if (i == 0) {
            root = input[0];
        }

        arr[input[0] - 'a'][0] = input[1];
        arr[input[0] - 'a'][1] = input[2];
    }

    printInOrder(root);

    return 0;
}