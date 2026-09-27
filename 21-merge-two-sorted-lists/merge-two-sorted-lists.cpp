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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newhead= new ListNode(NULL);
        if (list1==NULL and list2!=NULL){
            return list2;
        }
        if (list1!=NULL and list2==NULL){
            return list1;
        }
        if (list1==NULL and list2==NULL){
            return NULL;
        }
        if (list1->val<list2->val){
            newhead->val=list1->val;
            list1=list1->next;
        }else{
            newhead->val=list2->val;
            list2=list2->next;
        }
        ListNode* ans=newhead;
        while (list1!=NULL and list2!=NULL){
            if (list1->val<list2->val){
                ListNode* newnext= new ListNode(list1->val);
                newhead->next=newnext;
                newhead=newhead->next;
                list1=list1->next;
            }else{
                ListNode* newnext= new ListNode(list2->val);
                newhead->next=newnext;
                newhead=newhead->next;
                list2=list2->next;
            }
        }
        while (list1!=NULL){
            ListNode* newnext= new ListNode(list1->val);
            newhead->next=newnext;
            newhead=newhead->next;
            list1=list1->next;
        }
        while (list2!=NULL){
            ListNode* newnext= new ListNode(list2->val);
            newhead->next=newnext;
            newhead=newhead->next;
            list2=list2->next;
        }
        return ans;
    }
};