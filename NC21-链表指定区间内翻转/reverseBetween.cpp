/*
题目描述
将一个链表\ m m 位置到\ n n 位置之间的区间反转，要求时间复杂度 O(n)O(n)，空间复杂度 O(1)O(1)。
例如：
给出的链表为 1\to 2 \to 3 \to 4 \to 5 \to NULL 1→2→3→4→5→NULL, m=2,n=4m=2,n=4,
返回 1\to 4\to 3\to 2\to 5\to NULL 1→4→3→2→5→NULL.
注意：
给出的 mm,nn 满足以下条件：
1 <= m <= n <= 链表长度
示例1
输入
{1,2,3,4,5},2,4
返回值
{1,4,3,2,5}
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
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        /**思路:将链表分成3部分，1~m-1,m~n,n+1~end,然后将中间链表翻转，再重新连接*/
        int index = 0;//记录当前遍历到的元素位置
        ListNode* dummy_head = new ListNode(0);//构造一个哑元头节点，防止m=1时，没有第一部分
        dummy_head->next = head;
        ListNode* iter = dummy_head;//用于遍历
        ListNode *head_end, *mid_end;// 用来记录第一部分尾节点，和中间部分尾节点，便于翻转后连接
        ListNode *mid;
        while(iter) {
            if(index == m - 1) {
                mid = iter->next;//记录m位置
                iter->next = NULL;//将m-1和m位置断开，分开两段
                head_end = iter;//记录m-1位置
                break;
            }
            iter = iter->next;
            index++;
        }
        iter = mid;
        ListNode* tail;
        while(iter) {
            if(index == n - 1) {
                tail = iter->next;//记录n位置
                iter->next = NULL;//将n-1和n位置断开
                break;
            }
            iter = iter->next;
            index++;
        }
        ListNode *dummy_mid = new ListNode(0);//新建一个哑元，用于中间段翻转
        mid_end = mid;
        while(mid) {
            ListNode * temp = mid->next;
            mid->next = dummy_mid->next;
            dummy_mid->next = mid;
            mid = temp;
        }
        mid_end->next = tail;//将中间段和第三段连接
        head_end->next = dummy_mid->next;//将头段和中间段连接
        return dummy_head->next;
    }
};
