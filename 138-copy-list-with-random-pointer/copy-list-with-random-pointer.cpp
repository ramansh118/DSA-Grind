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
        if (head == NULL)
            return NULL;
        Node* temp=new Node(head->val);
        Node* ans =temp;
        Node* temp1=head->next;
        unordered_map<Node*,Node*>count;
        count[head]=temp;
        while (temp1!=NULL){
            Node* next=new Node(temp1->val);
            count[temp1]=next;
            temp->next = next;
            temp = temp->next;
            temp1=temp1->next;
        }
        temp=ans;
        temp1=head;
        while (temp1!=NULL and temp!=NULL){
            if (temp1->random==NULL){
                temp->random=NULL;
                temp=temp->next;
                temp1=temp1->next;
                continue;
            }
            temp->random=count[temp1->random];
            temp=temp->next;
            temp1=temp1->next;
        }
        return ans;
    }
};