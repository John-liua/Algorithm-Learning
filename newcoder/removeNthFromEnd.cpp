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
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode *now = head;
        ListNode *ls = head, *rs = head;
        int cnt = 0;
        int sum = 0;
        while(now){    //遍历链表
            sum ++;
            now = now->next;
            if(cnt > n){    //维护两个指针的距离为n + 1
                cnt --;
                ls = ls->next;
            }
            cnt ++;
        }
        if(sum == n){    //如果是删除第一个
            return head->next;
        }else if(n == 1){    //删除最后一个
            ls->next = NULL;
        }else
            ls->next = ls->next->next;
 
        return head;
    }
};