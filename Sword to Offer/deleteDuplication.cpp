/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if(pHead == NULL)
            return NULL;
        ListNode* res = new ListNode(0);
        res->next = pHead;
        ListNode* cur = res;
        while(cur->next != NULL && cur->next->next != NULL){
            if(cur->next->val == cur->next->next->val){
                int temp = cur->next->val;
                while(cur->next != NULL && cur->next->val == temp)
                    cur->next = cur->next->next;
            }
            else
                cur = cur->next;
        }
        return res->next;
    }
};