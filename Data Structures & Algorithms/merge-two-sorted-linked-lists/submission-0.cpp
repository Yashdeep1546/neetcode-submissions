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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1=list1, * curr2=list2;
        ListNode dummy(-1);
        ListNode* prev=&dummy;
        while(curr1!=nullptr&& curr2!=nullptr){
            if(curr1->val<=curr2->val){
                prev->next=curr1;
                curr1=curr1->next;
                
            }
            else{
                prev->next=curr2;
                curr2=curr2->next;
            }
            prev=prev->next;
        }
        if(curr1!=nullptr){
            prev->next=curr1;
        }
        if(curr2!=nullptr){
            prev->next=curr2;
        }
        return dummy.next;
    }
};
