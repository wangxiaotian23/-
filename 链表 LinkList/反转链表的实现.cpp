
/*
���Ե�ַ:
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
             ListNode* p=head->next;//�ȱ��棬��ֹ����
             head->next=t;//��headָ��head��ǰһ���ڵ�
             t=head;//�ƶ��ڵ�,��head��Ϊt
             head=p;//�ƶ��ڵ�,��head->next��Ϊhead
             
        }
        return t;
        
    }
};
