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
    bool ans=true;
    pair<long long,long long> solve(TreeNode* root){
        if(root==NULL) return {(long long)INT_MAX+1,(long long)INT_MIN-1};
        pair<long long,long long> l=solve(root->left);
        pair<long long,long long> r=solve(root->right);
        if(root->val<=l.second || root->val>=r.first){
            ans=false;
        }
        return {min(l.first,(long long)root->val),max(r.second,(long long)root->val)};
    }
    bool isValidBST(TreeNode* root) {
        solve(root);
        return ans;
        
    }
};