# [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/?envType=problem-list-v2&envId=2cktkvj)  
## 题目解答  
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        auto preHead = head;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                preHead->next = list1;
                list1 = list1->next;
            } else {
                preHead->next = list2;
                list2 = list2->next;
            }

            preHead = preHead->next;
        }

        preHead->next = (list1 == nullptr ? list2 : list1);

        return head->next;
    }
};
```

`递归解答`
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
```

> 这个递归方法十分值得思考！