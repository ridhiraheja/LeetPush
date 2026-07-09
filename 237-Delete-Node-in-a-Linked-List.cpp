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
    void deleteNode(ListNode* node) {
        //we will copy the value of nextnode to the node to be deleted and then delete the nextNode
        ListNode* nextNode=node->next;
        node->val=node->next->val;
        node->next=node->next->next;
        delete nextNode;

        
    }
};