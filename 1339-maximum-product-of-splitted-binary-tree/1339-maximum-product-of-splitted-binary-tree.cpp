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
    long long maxi=-1e9;
    long long tsum=0;
    long long mod=1e9+7;
    long long solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        long long lsum=solve(root->left);
        long long rsum=solve(root->right);
        return lsum+rsum+root->val;
    }
    long long solve2(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        long long lsum=solve2(root->left);
        long long rsum=solve2(root->right);
        long long currsum=tsum-(lsum+rsum);
        // cout<<lsum<<" "<<rsum<<" "<<currsum<<endl;
        maxi=max(maxi,(long long)(currsum+lsum)*rsum);
        maxi=max(maxi,(long long)(currsum+rsum)*lsum);
        return lsum+rsum+root->val;

    }
    int maxProduct(TreeNode* root) {
        tsum=solve(root);
        long long x=solve2(root);
        return  (maxi)%mod;
        
    }
};