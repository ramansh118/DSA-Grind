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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL){
            return head;
        }
        ListNode* temp1=head;
        int n=0;
        while (temp1!=NULL){
            temp1=temp1->next;
            n++;
        }
        k = k % n;

        if (k == 0) {
            return head;
        }
        int c=n-k;
        temp1=head;
        ListNode*temp2=temp1;
        while (c>0){
            temp2=temp1;
            temp1=temp1->next;
            c--;
        }
        temp2->next=NULL;
        ListNode* temp3=temp1;
        while (temp3->next!=NULL){
            temp3=temp3->next;
        }
        temp3->next=head;
        return temp1;
    }
};