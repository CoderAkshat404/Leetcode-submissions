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
    bool solve(TreeNode* root,long long ul,long long ll){
        if(root==NULL){
            return true;
        }
        if(root->val<=ll || root->val>=ul){
            return false;

        }
        return solve(root->left,root->val,ll) && solve(root->right,ul,root->val);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,1e10,-1e10);

        
    }
};