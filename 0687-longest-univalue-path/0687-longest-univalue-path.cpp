/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int ans = 0;

    int solve(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int leftPath = 0;
        int rightPath = 0;

        if (root->left != NULL && root->left->val == root->val)
            leftPath = left + 1;

        if (root->right != NULL && root->right->val == root->val)
            rightPath = right + 1;

        // Path passing through current node
        ans = max(ans, leftPath + rightPath);

        // Return the longer path to parent
        return max(leftPath, rightPath);
    }
    int longestUnivaluePath(TreeNode* root) {
        solve(root);
        return ans;
    }
};