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
    bool isPalindrome(ListNode* head) {
        ListNode* newNode = new ListNode(head->val);
        ListNode* temp=head;
        ListNode* tail=newNode;
        temp=temp->next;
        while(temp!=NULL){
            tail->next=new ListNode(temp->val);
            tail=tail->next;
            temp=temp->next;
        }
        ListNode* prev=NULL;
        ListNode* current=newNode;
        ListNode* next=newNode;
        while (current!=NULL){
            next=next->next;
            current->next=prev;
            prev=current;
            current=next;
        }

        while (prev!=NULL and head!=NULL){
            if (prev->val!=head->val){
                return false;
            }
            prev=prev->next;
            head=head->next;
        }
        return true;
 
    }
};