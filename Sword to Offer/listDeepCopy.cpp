/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(pHead == NULL)
            return pHead;
        RandomListNode *cur=pHead;
        while(cur!=NULL){
            RandomListNode *clone = new RandomListNode(cur->label);
            clone->next = cur->next;
            cur->next = clone;
            cur = clone->next;
        }
        cur = pHead;
        RandomListNode *clone = pHead->next;
        RandomListNode *res = pHead->next;
        while(cur!=NULL){
            if(cur->random==NULL)
                clone->random=NULL;
            else
                clone->random=cur->random->next;
            cur=cur->next->next;
            if(clone->next!=NULL)
                clone= clone->next->next;
        }
        cur = pHead;
        clone = pHead->next;
        while(cur!=NULL){
            cur->next=cur->next->next;
            cur=cur->next;
            if(clone->next!=NULL)
                clone->next=clone->next->next;
            clone =clone->next;
        }
        return res;
    }
};