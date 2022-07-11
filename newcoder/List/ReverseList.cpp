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
};