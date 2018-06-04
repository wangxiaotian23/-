
/*
测试地址:
		 https://www.lintcode.com/problem/reverse-linked-list/description
*/

/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode * reverse(ListNode * head) {
        // write your code here
        if(head==NULL){
            return head;
        }
        ListNode* t=NULL;
        while(head){
             ListNode* p=head->next;//先保存，防止断链
             head->next=t;//让head指向head的前一个节点
             t=head;//移动节点,让head变为t
             head=p;//移动节点,让head->next变为head
             
        }
        return t;
        
    }
};
