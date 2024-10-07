# [206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/description/?envType=problem-list-v2&envId=2cktkvj)  
## 题解  
`解法一：内存效率很糟糕`
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* nxt = nullptr;

        while (cur != nullptr) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        return pre;
    }
};
```  

`解法二：递归解法，比较巧妙`
```cpp 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* subHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return subHead;
    }
};
```
> 但这个方法的时间复杂度是O(N)，根据计算机知识可以知道，递归有更多的函数调用栈开销。空间复杂度是栈空间，是O(n)。
