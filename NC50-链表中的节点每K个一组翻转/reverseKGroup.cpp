/*
题目描述
将给出的链表中的节点每k 个一组翻转，返回翻转后的链表
如果链表中的节点数不是k 的倍数，将最后剩下的节点保持原样
你不能更改节点中的值，只能更改节点本身。
要求空间复杂度 O(1)
例如：
给定的链表是1\to2\to3\to4\to51→2→3→4→5
对于 k = 2 k=2, 你应该返回 2\to 1\to 4\to 3\to 5  2→1→4→3→5
对于 k = 3 k=3, 你应该返回 3\to2 \to1 \to 4\to 5  3→2→1→4→5

示例1
输入
{1,2,3,4,5},2
返回值
{2,1,4,3,5}
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
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseList(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        while(head) {
            ListNode *temp = head->next;
            head->next = dummy->next;
            dummy->next = head;
            head = temp;
        }
        return dummy->next;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        if(k == 1) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int index = 0;//记录遍历位置
        ListNode *iter = dummy;//用于遍历
        ListNode *head_end = dummy, *mid = head, *tail;//将链表分成3部分，已完成翻转的第一部分，将要返回的第二部分，还未翻转的第三部分
                                  //这三个变量分别记录第一分尾节点，和第二，三部分头节点，以便第二部分翻转后重新连接
        while(iter) {
            iter = iter->next;
            index++;
            if(index % k == 0 && iter) {
                tail = iter->next;//记录第三部分头节点
                head_end->next = NULL;//将第一，二部分断开
                iter->next = NULL;//将第二，三部分断开
                ListNode *iter_mid = mid;
                ListNode* mid_head = reverseList(iter_mid);
                mid->next = tail;//翻转后mid成了第二部分尾节点，将第二，三部分连接起来
                head_end->next = mid_head;//将第一，二部分连起来
                head_end = mid;
                mid = tail;
                iter = mid;
                index++;//iter偏移了一个位置，到了第三部分头部, 这里容易忽略导致出错
            }
        }
        return dummy->next;
    }
};
