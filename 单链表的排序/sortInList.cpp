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
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        // write code here
        if(!head || !head->next) return head;
        if(!head->next->next) {
            if(head->val < head->next->val) return head;
            else {
                ListNode *next = head->next;
                head->next = NULL;
                next->next = head;
                return next;
            }
        }
        ListNode* dummy_lower = new ListNode(0);
        ListNode* dummy_higher = new ListNode(0);
        ListNode* equal_list = head;
        int pivot = head->val;
        head = head->next;
        equal_list->next = NULL;
        while(head) {
            ListNode *temp = head->next;
            head->next = NULL;
            if(head->val < pivot) {
                head->next = dummy_lower->next;
                dummy_lower->next = head;
            } else if(head->val > pivot) {
                head->next = dummy_higher->next;
                dummy_higher->next = head;
            } else {
                head->next = equal_list->next;
                equal_list->next = head;
            }
            head = temp;
        }
        ListNode *lower = sortInList(dummy_lower->next);
        ListNode *higher = sortInList(dummy_higher->next);
        ListNode *iter = lower;
        while(iter && iter->next) iter = iter->next;
        if(iter) iter->next = equal_list;
        ListNode* iter_equal = equal_list;
        while(iter_equal->next) iter_equal = iter_equal->next;
        iter_equal->next = higher;
        if(lower) return lower;
        else return equal_list;
    }
};
