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
    int ans=0;
    int solve(TreeNode* root){
        if(root==NULL){
            return -1e9;
        }
        int lm=solve(root->left);
        int rm=solve(root->right);
        if(root->val>=lm && root->val>=rm){
            ans++;
        }
        return max(rm,max(lm,root->val));
    }
    int countDominantNodes(TreeNode* root) {
        solve(root);
        return ans;
        
    }
};