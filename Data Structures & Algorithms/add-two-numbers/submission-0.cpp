/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* c1=l1,*c2=l2;
        ListNode dummy(-1);
        ListNode* c=&dummy;
        int carry=0;
        while(c1!=nullptr && c2!=nullptr){
            int total=c1->val+c2->val+ carry;
            ListNode* temp=new ListNode(total%10);
            carry=total/10;
            c->next=temp;
            c=c->next;
            c1=c1->next;
            c2=c2->next;
        }

        while(c1!=nullptr){
            int total=c1->val+ carry;
            ListNode* temp=new ListNode(total%10);
            carry=total/10;
            c->next=temp;
            c=c->next;
            c1=c1->next;
            
        }
        while(c2!=nullptr){
            int total=c2->val+ carry;
            ListNode* temp=new ListNode(total%10);
            carry=total/10;
            c->next=temp;
            c=c->next;
            c2=c2->next;
        }
        if(carry!=0){
             ListNode* temp=new ListNode(carry);
             c->next=temp;
        }
        return dummy.next;
    }
};
