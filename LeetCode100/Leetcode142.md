# [142. 环形链表2](https://leetcode.cn/problems/linked-list-cycle/submissions/570768662/?envType=problem-list-v2&envId=2cktkvj)
## 题目解答  
我来简洁清晰地分析一下快慢指针吧。

重画链表如下所示，线上有若干个节点。记蓝色慢指针为 slow，红色快指针为 fast。初始时 slow 和 fast 均在头节点处。0208_2.png使 slow 和 fast 同时前进，fast 的速度是 slow 的两倍。当 slow 抵达环的入口处时，fast 一定在环上，如下所示。0208_3.png其中：

head 和 A 的距离为 z
弧 AB (沿箭头方向) 的长度为 x
同理，弧 BA 的长度为 y
可得：

slow 走过的步数为 z
设 fast 已经走过了 k 个环，k≥0，对应的步数为 z+k(x+y)+x
以上两个步数中，后者为前者的两倍，即 2z=z+k(x+y)+x 化简可得 z=x+k(x+y)，替换如下所示。

0208_4.png此时因为 fast 比 slow 快 1 个单位的速度，且y 为整数，所以再经过 y 个单位的时间即可追上 slow。

即 slow 再走 y 步，fast 再走 2y 步。设相遇在 C 点，位置如下所示，可得弧 AC 长度为 y。0208_5.png因为此前x+y 为环长，所以弧 CA 的长度为 x。 此时我们另用一橙色指针 ptr (pointer) 指向 head，如下所示。并使 ptr 和 slow 保持 1 个单位的速度前进，在经过 z=x+k(x+y) 步后，可在 A 处相遇。0208_6.png再考虑链表无环的情况，fast 在追到 slow 之前就会指向空节点，退出循环即可。

官方题解跳过了 fast 和 slow 一定会相遇的证明，而且也没有标明 c 的含义。

## 解答
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        auto fast = head;
        auto slow = head;

        do {
            if (fast == nullptr || fast->next == nullptr) {
                return nullptr;
            }
            else {
                fast = fast->next->next;
                slow = slow->next;
            }
        } while(fast != slow);

        auto another = head;
        while (another != slow) {
            slow = slow->next;
            another = another->next;
        }

        return another;
    }
};
```