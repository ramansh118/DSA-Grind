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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k==1 || head->next==NULL){
            return head;
        }
        ListNode*temp=head;
        int n=0;
        while (temp!=NULL){
            n++;
            temp=temp->next;
        }
        int c=n/k;
        n=k;
        ListNode*temp2=head;
        ListNode*temp1=NULL;
        ListNode* prev=temp1;
        ListNode* last=temp1;
        ListNode* ans=temp1;

        for (int i=0;i<c;i++){
            prev=NULL;
            ListNode* current=temp2;
            ListNode* next=temp2;
            ListNode* groupStart = temp2;
            while (n>0){
                temp1=temp2;
                temp2=temp2->next;
                n--;
            }
            n=k;
            
            while (current!=temp2){
                next=current->next;
                current->next=prev;
                prev=current;
                current=next;
            }
            if (ans==NULL){
                ans=prev;
            }
            if(last!=NULL){
                last->next=prev;
            }
            last = groupStart;
            last->next = temp2; 


            

        }
        return ans;
    }
};