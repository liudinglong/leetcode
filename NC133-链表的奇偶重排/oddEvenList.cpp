/*
题目描述
给定一个单链表，请设定一个函数，将链表的奇数位节点和偶数位节点分别放在一起，重排后输出。
注意是节点的编号而非节点的数值。
示例1
输入

{1,2,3,4,5,6}
返回值

{1,3,5,2,4,6}
说明
1->2->3->4->5->6->NULL
重排后为
1->3->5->2->4->6->NULL

示例2
输入

{1,4,6,3,7}
返回值

{1,6,7,4,3}
说明
1->4->6->3->7->NULL
重排后为
1->6->7->4->3->NULL

奇数节点有1,6,7，偶数节点有4,3。重排后为1,6,7,4,3

备注:
链表长度不大于200000。每个数范围均在int内。
*/
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* oddEvenList(ListNode* head) {
        // write code here
        if(!head || !head->next) return head;
        ListNode *odd_dummy = new ListNode(0);
        ListNode *odd_iter = odd_dummy;
        ListNode *even_dummy = new ListNode(0);
        ListNode *even_iter = even_dummy;
        while(head) {
            ListNode * next_node = head->next;
            head->next = NULL;
            odd_iter->next = head;
            odd_iter = odd_iter->next;
            if(!next_node) break;//到结尾了，退出循环
            head = next_node->next;
            next_node->next = NULL;
            even_iter->next = next_node;
            even_iter = even_iter->next;
         }
         odd_iter->next = even_dummy->next;
         even_dummy->next = NULL;
         delete even_dummy;//delete 掉new的两个哑元节点
         head = odd_dummy->next;
         delete odd_dummy;//delete 掉new的两个哑元节点
         return head;
    }
};