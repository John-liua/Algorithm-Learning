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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* N1=pHead1;
        ListNode* N2=pHead2;
        while(N1!=N2)
        {
            if(N1)
                N1=N1->next;
            else
                N1=pHead2;
            if(N2)
                N2=N2->next;
            else
                N2=pHead1;
        }
        return N1;
    }
};