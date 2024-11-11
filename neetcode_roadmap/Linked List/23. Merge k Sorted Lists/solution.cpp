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
    struct compareNode{
        bool operator()(const ListNode* a,const ListNode* b){
            return a->val>b->val;
        }
    };

    // gives minimum
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*>,compareNode> pq;

        for(auto x:lists){
            while(x){
                pq.push(x);
                x=x->next;
            }
        }
        ListNode* ans=new ListNode();
        ListNode* ansReal=ans;
        while(!pq.empty()){
            ans->next=pq.top();
            pq.pop();
            ans=ans->next;
            ans->next=nullptr; // cause eder modhdhe link ase. link chutaite hobe.
        }
        return ansReal->next;


    }
};
