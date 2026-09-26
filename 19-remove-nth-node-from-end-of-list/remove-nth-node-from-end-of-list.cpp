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
        ListNode*temp=head;
        int n1=0;

        while (temp!=NULL){
            n1++;
            temp=temp->next;
        }
        if (n == n1) {
            return head->next;
        }
        ListNode*temp1=head;
        ListNode*prev=head;
        
        int c=n1-n;
        while (temp1!=NULL and c>0){
            prev=temp1;
            c--;
            temp1=temp1->next;
            
        }
        prev->next=temp1->next;
        return head;
    }
};