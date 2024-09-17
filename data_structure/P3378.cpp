#include <bits/stdc++.h>
using namespace std;

const int N = 1000004;
int heap[N];
int len = 0;

// 向堆中插入元素
void push(int num) {
    heap[++len] = num;
    int index = len;

    // 上浮操作
    while (index > 1 && heap[index / 2] > heap[index]) {
        swap(heap[index / 2], heap[index]);
        index /= 2;
    }
}

// 删除堆顶元素
void pop() {
    if (len == 0) return; // 堆为空时直接返回

    swap(heap[1], heap[len--]);  // 将堆顶和最后一个元素交换，并减少长度
    int index = 1;

    // 下沉操作
    while (2 * index <= len) {
        int child = 2 * index;  // 左孩子
        // 如果有右孩子，并且右孩子比左孩子小，选择右孩子
        if (child + 1 <= len && heap[child + 1] < heap[child]) {
            child = child + 1;
        }
        // 如果当前节点比孩子节点小，则停止下沉
        if (heap[index] <= heap[child]) break;
        swap(heap[index], heap[child]);  // 交换节点和孩子节点
        index = child;  // 更新索引为孩子节点
    }
}

int main() {
    int n, op, num;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> op;
        switch (op) {
            case 1:  // 插入操作
                cin >> num;
                push(num);
                break;
            case 2:  // 输出堆顶元素
                if (len == 0) {
                    cout << 0 << endl;  // 输出0而不是字符'0'
                } else {
                    cout << heap[1] << endl;  // 输出堆顶元素
                }
                break;
            case 3:  // 删除堆顶元素
                pop();
                break;
        }
    }
    return 0;
}
