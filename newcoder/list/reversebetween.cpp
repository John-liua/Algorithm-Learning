/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode L = ListNode(0);
        L.next = head;
        ListNode *p = &L;
        ListNode *q = head;
        for(int i=1;i<m;i++)
        {
        	p = q;
        	q = q->next;
		}
		for(int i=0;i<n-m;i++)
		{
			ListNode *t = q->next;
			q->next = t->next;
			t->next = p->next;
			p->next = t;
		}
		return L.next;
    }
};