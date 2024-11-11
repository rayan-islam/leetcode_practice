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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next){
            return;
        }
        
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* prev=nullptr;
        ListNode* temp=slow->next;
        slow->next=nullptr;
        slow = temp;
        while(slow){
            temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        
        ListNode* ans=new ListNode();
        while(head ||prev){
            if(head){
                ans->next=head;
                ans=ans->next;
                head=head->next;
            }
            if(prev){

                ans->next=prev;
                ans=ans->next;
                prev=prev->next;            
            }
        }
        head=ans->next;

    }
};