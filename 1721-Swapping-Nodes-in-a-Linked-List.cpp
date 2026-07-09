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
    ListNode* kthNode(ListNode* head,int k){
        for(int i=1;i<k;i++){
            head=head->next;
        }
        return head;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forw=NULL;

        while(curr){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;

        }
        return prev;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(head->next==NULL) return head;
        ListNode* front=kthNode(head,k);
        ListNode* revhead=reverse(head);
        ListNode* back=kthNode(revhead,k);

        swap(front->val,back->val);
        return reverse(revhead);
        
    }
};