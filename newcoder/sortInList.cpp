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
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        vector<int> nums;
        ListNode* p=head;
        while(p!=NULL)
        {
            nums.push_back(p->val);
            p=p->next;
        }
        p=head;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            p->val=nums[i];
            p=p->next;
        }
        return head;
    }
};