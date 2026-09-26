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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        int n1=0;
        while (temp1!=NULL){
            n1++;
            temp1=temp1->next;
        }
        int n2=0;
        ListNode* temp2=headB;
        while (temp2!=NULL){
            n2++;
            temp2=temp2->next;
        }
        ListNode* first=headA;
        ListNode* second=headB;
        if (n1>n2){
            int n=n1-n2;
            while (n>0){
                first=first->next;
                n--;
            }
        }else{
            int n=n2-n1;
            while(n>0){
                second=second->next;
                n--;
            }
        }
        while (first!=NULL and second!=NULL){
            if (first==second){
                return first;
            }
            first=first->next;
            second=second->next;
        }
        return NULL;
    }
};