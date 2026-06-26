/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
        return NULL;
        Node* tracker=head;
        Node* head2=new Node(head->val);
        Node* tracker2=head2;
        unordered_map <Node*,Node*> m;
        unordered_map <Node*,Node*> n;
        n[head]=head2;
        m[head]=head->random;
        while(tracker->next !=NULL){
            tracker=tracker->next;
            Node* newnode=new Node(tracker->val);
            tracker2->next=newnode;
            tracker2=tracker2->next;
            n[tracker]=tracker2;
            m[tracker]=tracker->random;
        }
        tracker2 = head2;
        tracker = head;
        while(tracker2 !=NULL){
            tracker2->random = n[m[tracker]];
            tracker2 = tracker2->next;
            tracker = tracker->next;
        }
    return head2;
    }
};