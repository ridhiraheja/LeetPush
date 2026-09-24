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
    ListNode* merge(ListNode* list1,ListNode* list2){
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                curr->next=list1;
                list1=list1->next;
            }else{
                curr->next=list2;
                list2=list2->next;

            }
            curr=curr->next;
        }
        if(list1 != NULL) {
            curr->next = list1;
        }

        if(list2 != NULL) {
            curr->next = list2;
        }

        return dummy->next;
    }
    ListNode* mergeSort(vector<ListNode*>&lists,int l,int r){
        if(l>r)return NULL;
        if(l==r) return lists[l];
        int mid=l+(r-l)/2;
        ListNode* left = mergeSort(lists,l,mid);
        ListNode* right = mergeSort(lists,mid+1,r);
        return merge(left,right);


    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        return mergeSort(lists,0,lists.size()-1);

        
    }
};