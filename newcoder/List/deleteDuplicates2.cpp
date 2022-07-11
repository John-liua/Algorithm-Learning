/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return head;
        //创建新的表头
        ListNode* res=new ListNode(0);
        res->next=head;
        ListNode* cur=res;
        while(cur->next!=NULL&&cur->next->next!=NULL)
        {
            if(cur->next->val==cur->next->next->val){
                //跳过中间所有的重复节点
                int temp=cur->next->val;
                while(cur->next!=NULL&&cur->next->val==temp)
                    cur->next=cur->next->next;
            }
            else
                cur=cur->next;
        }
        return res->next;
    }
};