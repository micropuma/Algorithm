# [160. 相交链表](https://leetcode.cn/problems/intersection-of-two-linked-lists/description/?envType=problem-list-v2&envId=2cktkvj)  
## 思路  
* 让指针 PA 和 pB 分别指向链表 A 和链表 B 的头结点，之后两个指针分别以步幅为 1 的速度向链表的尾部遍历。当指针 pA 遍历到链表 A 的尾节点时，此时指针 pA 走了 a 个节点，将指针 pA 指向链表 B 的头部，继续向后遍历，直至走到 c1，此时指针 PA 总共走了 a + ( b - c ) 步。
当指针 pB 遍历到链表 B 的尾节点时，此时指针 pB 走了 b 个节点，将指针 pB 指向链表 A 的头部，继续向后遍历，直至走到 c1，此时指针 PB 总共走了 b + ( a - c ) 步。
* 如果不相交，则会同时指向null（**最小公倍数**）。  

## 解答    
`方法一`
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) {
            return NULL;
        }

        ListNode *pointerA = headA;
        ListNode *pointerB = headB;

        while (pointerA != pointerB) {
            pointerA = (pointerA == NULL ? headB : pointerA->next);
            pointerB = (pointerB == NULL ? headA : pointerB->next);
        }

        return pointerA;
    }
};
```  

`方法二：做对齐`
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) {
            return NULL;
        }

        int lenA = 0;
        int lenB = 0;
        ListNode *pointerA = headA;
        ListNode *pointerB = headB;

        while (pointerA != NULL) {
            lenA ++;
            pointerA = pointerA->next;
        }

        while (pointerB != NULL) {
            lenB ++;
            pointerB = pointerB->next;
        }

        pointerA = headA;
        pointerB = headB;

        if (lenA > lenB) {
            for (int i = 0; i < lenA-lenB; i++) {
                pointerA = pointerA->next;
            }
        } else {
            for (int i = 0; i < lenB-lenA; i++) {
                pointerB = pointerB->next;
            }
        }  

        while (pointerA != pointerB) {
            pointerA = pointerA->next;
            pointerB = pointerB->next;
        } 

        return pointerA;
    }   
};
```