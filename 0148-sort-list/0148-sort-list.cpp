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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Divide into two lists
        ListNode* second = slow->next;
        slow->next = NULL;

        // Sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(second);

        // Merge sorted halves
        return merge(left, right);
    }

      ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (left != NULL && right != NULL) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        if (left != NULL)
            tail->next = left;

        if (right != NULL)
            tail->next = right;

        return dummy.next; 
    }
};