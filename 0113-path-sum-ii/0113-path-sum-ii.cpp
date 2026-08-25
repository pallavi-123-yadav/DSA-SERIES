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
vector<vector<int>>ans;
void  fun(TreeNode* root, int sum, int target,
             vector<int>& path) {
                if(root==NULL) return ;
                sum =sum+root->val;
     path.push_back(root->val);
     if(root->left==NULL && root->right==NULL) {
        if(sum==target) {
            ans.push_back(path);
            
        }
    path.pop_back();
            return;
     }
     fun(root->left,sum,target,path);
     fun(root->right,sum,target,path);
    path.pop_back();
             }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            vector<int> path;
        fun(root,0,targetSum,path);
        return ans;
    }
};