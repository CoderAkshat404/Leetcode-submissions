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
    void solve(TreeNode* &root){
        if(root->left==NULL && root->right==NULL){
            return;
        }
         TreeNode* x=root->left;
         TreeNode* y=root->right;
         root->left=y;
         root->right=x;
         if(root->left!=NULL){
            solve(root->left);
         }
         if(root->right!=NULL){
            solve(root->right);
         }
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
         solve(root);
         return root;

        
    }
};