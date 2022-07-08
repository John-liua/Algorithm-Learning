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
    bool hasCycle(ListNode *head) {
        map<ListNode*,int>visited;
        while(head)
        {
            if(visited[head])
                return true;
            visited[head]=1;
            head=head->next;
        }
        return false;
    }
};