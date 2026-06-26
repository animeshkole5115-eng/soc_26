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
      ListNode* slow=head;
      ListNode* fast=head;
      if(head==NULL || head->next == NULL || head->next->next ==NULL)
      return ;
      while(fast != NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
      }
      ListNode* list2 = slow->next;
      slow->next = NULL;
      ListNode* prev = NULL;
      ListNode* nxt = list2->next;
      ListNode* curr = list2;
      while(curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr=nxt;
      }
       ListNode* first = head;
    ListNode* second = prev;   // head of reversed second half
      while(second){
    ListNode* temp1 = first->next;
    ListNode* temp2 = second->next;

    first->next = second;
    second->next = temp1;

    first = temp1;
    second = temp2;
}
      return;

    }
};