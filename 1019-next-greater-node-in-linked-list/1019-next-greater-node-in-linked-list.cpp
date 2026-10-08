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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> st;

        ListNode* temp = head;

        while (temp != NULL) {
            ans.push_back(temp->val);
            temp = temp->next;
        }

        for (int i = 0; i < ans.size(); i++) {

            while (!st.empty() && ans[i] > ans[st.top()]) {
                ans[st.top()] = ans[i];
                st.pop();
            }

            st.push(i);
        }

        while (!st.empty()) {
            ans[st.top()] = 0;
            st.pop();
        }

        return ans;
        
    }
};