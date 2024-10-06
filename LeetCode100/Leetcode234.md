# [234. 回文链表](https://leetcode.cn/problems/palindrome-linked-list/solutions/457059/hui-wen-lian-biao-by-leetcode-solution/?envType=problem-list-v2&envId=2cktkvj)  
## 解答  
本题的难点，是要求**时间复杂度是O(n)，空间复杂度是O(1)**。这就使得诸如栈，翻转全部链表的方法全部失效。正确解法是找到中间点，并翻转部分链表，然后翻转后半部分链表，然后前半部分和后半部分比较即可。  

## 代码  
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
    ListNode *middleNode(ListNode *head) {
        // 用快慢指针找到middle ptr.
        auto slowPtr = head;
        auto fastPtr = head;

        while(fastPtr != NULL && fastPtr->next != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        return slowPtr;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *pre = NULL;
        ListNode *nxt = NULL;
        auto curr =head;

        if (curr == NULL) {
            return NULL;
        }

        while (curr != NULL) {
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }

        return pre;
    }

    bool isPalindrome(ListNode* head) {
        auto mid = middleNode(head);
        auto reverseHead = reverseList(mid);

        while(head != mid) {
            if (head->val != reverseHead->val) {
                return false;
            }
            head = head->next;
            reverseHead = reverseHead->next;
        }

        return true;
    }
};
```