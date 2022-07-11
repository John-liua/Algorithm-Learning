/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
//方法1:把链表转换成数组，比较数组头尾的数字
class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        //把链表换成数组，这样才可以比较头尾数字是否相同
        vector<int> nums; 
        ListNode* p=head;
        while(p!=NULL)
        {
            nums.push_back(p->val);
            p=p->next;
        }
        int len=nums.size();  //数组长度
        //比较头和尾
        for(int i=0;i<len/2;i++)
        {
            if(nums[i]!=nums[len-i-1])
                return false;
        }
        return true;
    }
};

/*方法2:运用快慢指针，快指针是满纸真的二倍，当快指针到链表尾部时，慢指针到链表中间
反转慢指针，快指针移动到表头。然后进行比较*/
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
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    ListNode* reverse(ListNode* pHead) 
    {
        if(pHead==NULL)
            return NULL;
        ListNode* cur=pHead;
        ListNode* pre=NULL;
        while(cur!=NULL)
        {
            ListNode* temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp; 
        }
        return pre;
    }
    bool isPail(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=NULL&&fast!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast!=NULL)//fast不为空说明链表有奇数个
            slow=slow->next;
        slow=reverse(slow);
        fast=head;
        while(slow!=NULL)
        {
            if(fast->val!=slow->val)
                return false;
            fast=fast->next;
            slow=slow->next;
        }
        return true;
    }
};