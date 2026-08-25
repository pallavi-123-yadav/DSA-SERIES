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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return NULL;
         int rootvalue =preorder[0];
         TreeNode* root =new TreeNode(rootvalue);
int index =0;
         while(inorder[index]!=rootvalue) {
            index++;
         }
        vector<int> leftPreorder(
            preorder.begin() + 1,
            preorder.begin() + 1 + index
        );

        vector<int> leftInorder(
            inorder.begin(),
            inorder.begin() + index
        );

        vector<int> rightPreorder(
            preorder.begin() + 1 + index,
            preorder.end()
        );

        vector<int> rightInorder(
            inorder.begin() + index + 1,
            inorder.end()
        );

        // 4. Recursively build subtrees
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};