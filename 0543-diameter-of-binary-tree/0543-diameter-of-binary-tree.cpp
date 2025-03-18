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
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return max(1+solve(root->left),1+solve(root->right));

    }
    void solve2(int &maxi,TreeNode* root){
        if(root==NULL){
            return;
        }
        maxi=max(maxi,solve(root->left)+solve(root->right));
        solve2(maxi,root->left);
        solve2(maxi,root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=INT_MIN;
        solve2(maxi,root);
        return maxi;
        
    }
};