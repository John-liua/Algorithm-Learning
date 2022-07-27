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
    //法1:哈希表
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, ListNode*>visited;
        ListNode* pre=head;
        ListNode* cur=head;
        while(cur)
        {
            visited.find(cur->val)==visited.end();
            if(visited.count(cur->val)>=1)
                pre->next=cur->next;//去除当前节点
            else
            {
                visited[cur->val]=cur;
                pre=cur;     
            }
            cur=cur->next;
        }
        return head;
    }

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
    //法2: 顺序判断
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur=head;
        if(cur==NULL)
            return NULL;
        while(cur->next!=NULL)
        {
            if(cur->val==cur->next->val)
                cur->next=cur->next->next;
            else
                cur=cur->next;
        }
        return head;
    }
};
};