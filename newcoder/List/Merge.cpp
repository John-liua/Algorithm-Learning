/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode newNode=ListNode(0);
        ListNode *cur=&newNode;
        if(pHead1==NULL)
            return pHead2;
        if(pHead2==NULL)
            return pHead1;
        while(pHead1&&pHead2)
        {
            if(pHead1->val>=pHead2->val)
            {
                cur->next=pHead2;
                pHead2=pHead2->next;
            }else
            {
                cur->next=pHead1;
                pHead1=pHead1->next;
            }
            cur=cur->next;
        }if(pHead1!=NULL)
            cur->next=pHead1;
        else
            cur->next=pHead2;
     return newNode.next;
    }
};