# [141. 环形链表](https://leetcode.cn/problems/linked-list-cycle/?envType=problem-list-v2&envId=2cktkvj)
## 题解  
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> hasSeen;

        while(head != NULL) {
            if (hasSeen.count(head)) {
                return true;
            }

            hasSeen.insert(head);
            head = head->next;
        }

        return false;
    }
};
```

```cpp  
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 快慢指针写法  
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        auto slow = head;
        auto fast = head->next;

        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }

            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};
```
