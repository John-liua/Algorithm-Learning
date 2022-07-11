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
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto node=head;
        for(int i=0;i<k;i++)
        {
            if(!node)
                return head;
            node=node->next;
        }
        auto res=reverseList(head,node);
        head->next=reverseKGroup(node,k);
        return res;
    }
    private:
    ListNode* reverseList(ListNode* left,ListNode* right)
    {
        auto pre=right;
        while(left!=right)
        {
            auto node=left->next;
            left->next=pre;
            pre=left;
            left=node;
        }
        return pre;
    }
};