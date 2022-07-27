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
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
   ListNode* ReverseList(ListNode* pHead) 
    {
        if(pHead==NULL)
            return NULL;
        ListNode* cur=pHead;
        ListNode* pre=NULL;
        while(cur!=NULL)
        {
            ListNode* temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp; 
        }
        return pre;
    }
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        if(head1==NULL)
            return head2;
        if(head2==NULL)
            return head1;
        head1=ReverseList(head1);
        head2=ReverseList(head2);
        ListNode* head=new ListNode(-1);
        ListNode* nhead=head;
        int tmp=0;
        while(head1!=NULL||head2!=NULL)
        {
            int val=tmp;
            if(head1!=NULL)
            {
                val+=head1->val;
                head1=head1->next;
            }
             if(head2!=NULL)
            {
                val+=head2->val;
                head2=head2->next;
            }
            tmp=val/10;
            nhead->next=new ListNode(val%10);
            nhead =nhead->next;
        }if(tmp>0)
            nhead->next=new ListNode(tmp);
        return ReverseList(head->next);
    }
};