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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* newNode= new ListNode(0);
        ListNode* cur=newNode;
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
        }
        if(pHead1!=NULL)
            cur->next=pHead1;
        else
            cur->next=pHead2;
     return newNode->next;
    }
    ListNode* divideMerge(vector<ListNode *> &lists, int left, int right)
    {
        if(left>right)
            return NULL;
        else if(left==right)
            return lists[left];
        int mid= (left+right)/2;
        return Merge(divideMerge(lists,left,mid),divideMerge(lists,mid+1,right));
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return divideMerge(lists, 0, lists.size()-1);
    }
};