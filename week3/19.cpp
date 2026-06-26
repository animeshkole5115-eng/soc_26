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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast=head;
        int k=0;
        if(head->next == NULL){
            if(n==1)return NULL;
            else
            return head;
        }
        while(fast->next != NULL ){
            if(k==n){
                slow=head;
                k++;
                continue;
            }
            if(k>=n){
                slow=slow->next;
            }
            fast=fast->next;
            k++;
        }
        if(k<n){
            return head->next;
        }
        if(slow->next !=fast)
        slow->next=slow->next->next;
        else
        slow->next=NULL;
        return head;
    }
};