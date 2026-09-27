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
private:
   ListNode* merge(ListNode* list1, ListNode* list2) {

        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;

        ListNode* newhead = NULL;
        ListNode* tail = NULL;

        if (list1->val < list2->val) {
            newhead = list1;
            list1 = list1->next;
        }
        else {
            newhead = list2;
            list2 = list2->next;
        }

        tail = newhead;

        while (list1 != NULL && list2 != NULL) {

            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        if (list1 != NULL)
            tail->next = list1;
        else
            tail->next = list2;

        return newhead;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head==NULL || head->next==NULL){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while (fast!=NULL and fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        return merge(left,right);
        
    }
};