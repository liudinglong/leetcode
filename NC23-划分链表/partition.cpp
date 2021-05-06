/*
题目描述
给出一个链表和一个值 ，以 为参照将链表划分成两部分，使所有小于 的节点都位于大于或等于 的节点之前。
两个部分之内的节点之间要保持的原始相对顺序。
例如：
给出 1\to 4 \to 3 \to 2 \to 5 \to 2 1→4→3→2→5→2 和 x=3,
返回 1\to 2 \to 2 \to 4 \to 3 \to 5 1→2→2→4→3→5.
示例1
输入
{1,4,3,2,5,2},3
返回值
{1,2,2,4,3,5}
*/
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param x int整型 
     * @return ListNode类
     */
    ListNode* partition(ListNode* head, int x) {
        // write code here
        ListNode *lower_dummy = new ListNode(0);
        ListNode *higher_dummy = new ListNode(0);
        ListNode *lower_iter = lower_dummy;
        ListNode *higher_iter = higher_dummy;
        while(head) {
            ListNode *next_node = head->next;
            head->next = NULL;
            if(head->val < x) {
                lower_iter->next = head;
                lower_iter = lower_iter->next;
            } else {
                higher_iter->next = head;
                higher_iter = higher_iter->next;
            }
            head = next_node;
        }
        lower_iter->next = higher_dummy->next;
        head = lower_dummy->next;
        delete lower_dummy;
        delete higher_dummy;
        return head;
    }
};
