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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = NULL;
        ListNode* temp = NULL;
        int c = 0;

        while (l1 != NULL || l2 != NULL) {

            int sum = c;

            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            int digit = sum % 10;
            c = sum / 10;

            ListNode* newNode = new ListNode(digit);

            if (head == NULL) {
                head = newNode;
                temp = head;
            }
            else {
                temp->next = newNode;
                temp = temp->next;
            }
        }

        if (c != 0) {
            temp->next = new ListNode(c);
        }

        return head;
    }
};