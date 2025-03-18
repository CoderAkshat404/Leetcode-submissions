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
    int solve(TreeNode* root,int &maxi){
        if(root==NULL){
            return 0;
        }
        int l=solve(root->left,maxi);
        int r=solve(root->right,maxi);
        l=max(0,l);
        r=max(0,r);
        int c=root->val+r+l;
        maxi=max(maxi,c);
        return max(l,r)+root->val;


    }
    int maxPathSum(TreeNode* root) {
        int maxi=-1e9;
        int ans=solve(root,maxi);
        return maxi;
        
    }
};