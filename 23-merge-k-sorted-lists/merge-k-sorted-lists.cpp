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
    ListNode* mini(vector<ListNode*>& lists){
        int n=lists.size();
        int minn=INT_MAX;
        for(int i=0;i<n;i++){
            ListNode* temp=lists[i];
            if (temp==NULL){
                continue;
            }
            minn=min(minn,lists[i]->val);
        }
        for(int i=0;i<n;i++){
            ListNode* temp=lists[i];
            if (temp==NULL){
                continue;
            }
            if (minn==temp->val){
                lists[i]=lists[i]->next;
                return temp;
            }
        }
        return NULL;
    }
    bool valid(vector<ListNode*>& lists){
        int n=lists.size();
        for(int i=0;i<n;i++){
            if (lists[i]!=NULL){
                return true;
            }
        }
        return false;
        
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        ListNode* temp=mini(lists);
        if (temp==NULL){
            return NULL;
        }
        ListNode* newhead= new ListNode(temp->val);
        ListNode* ans=newhead;
        while(valid(lists)){
            ListNode* temp=mini(lists);
            newhead->next=temp;
            newhead=newhead->next;
        }
        return ans;


    }
};