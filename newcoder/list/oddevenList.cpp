/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    /*双指针指的是在遍历对象的过程中，不是普通的使用单个指针进行访问，而是使用两个指针
    （特殊情况甚至可以多个），两个指针或是同方向访问两个链表、或是同方向访问一个链表
    （快慢指针）、或是相反方向扫描（对撞指针），从而达到我们需要的目的。*/
    /*step 1：判断空链表的情况，如果链表为空，不用重排。
      step 2：使用双指针odd和even分别遍历奇数节点和偶数节点，并给偶数节点链表一个头。
      step 3：上述过程，每次遍历两个节点，且even在后面，因此每轮循环用even检查后两个元素是否为NULL，如果不为再进入循环进行上述连接过程。
      step 4：将偶数节点头接在奇数最后一个节点后，再返回头部。*/
    ListNode* oddEvenList(ListNode* head) {
        //空链表不用重新排序
        if(head==NULL)
            return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenhead=even; //保留偶数表头
        while(even!=NULL&&even->next!=NULL)
        {
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=evenhead; //奇数后面接偶数表
        return head;
    }
};