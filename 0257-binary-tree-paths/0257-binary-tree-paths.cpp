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
 vector<string>res;
  void fun(TreeNode* root,string path) {
    
    if(root==NULL) return ;
    if (path == "")
            path = to_string(root->val);
        else
            path += "->" + to_string(root->val);
if(root->left==NULL && root->right==NULL){
    res.push_back(path);
    return;
}
    fun(root->left,path);
    fun(root->right,path);
  }
    vector<string> binaryTreePaths(TreeNode* root) {
        fun (root,"");
        return res;
    }
};