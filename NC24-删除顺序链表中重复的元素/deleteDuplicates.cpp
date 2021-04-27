/*
题目描述
给出一个升序排序的链表，删除链表中的所有重复出现的元素，只保留原链表中只出现一次的元素。
例如：
给出的链表为1 \to 2\to 3\to 3\to 4\to 4 \to5 1→2→3→3→4→4→5, 返回1\to 2\to5 1→2→5.
给出的链表为1\to1 \to 1\to 2 \to 3 1→1→1→2→3, 返回2\to 3 2→3.

示例1
输入
{1,2,2}
返回值
{1}
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
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        ListNode *dummy = new ListNode(0); //创建一个哑元节点，便于删除开头的重复节点
        dummy->next = head;
        ListNode *iter = head;
        ListNode *pre_node = dummy;
        int cur_val = INT_MAX;
        int count = 0;
        while(iter) {
            if(cur_val == iter->val) {
               count++;
               iter = iter->next;
               if(count > 1) {
                   pre_node->next = iter;//把所有重复节点删除
               }
            } else{
                cur_val = iter->val;
                count = 1;
                if(iter->next && iter->next->val != cur_val)//下一个节点与当前节点不重复时，才设置当前节点为pre_node
                    pre_node = iter;
                iter = iter->next;
            }
        }
        return dummy->next;
    }
};
