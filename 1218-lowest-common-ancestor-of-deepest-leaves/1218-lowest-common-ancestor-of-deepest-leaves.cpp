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
    int calculateh(TreeNode* root){
        if(root==NULL) return 0;
        int l=1+calculateh(root->left);
        int r=1+calculateh(root->right);
        return max(l,r);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL) return NULL;
        int l=calculateh(root->left);
        int r=calculateh(root->right);
        if(l==r) return root;
        if(l>r) return lcaDeepestLeaves(root->left);
        else return lcaDeepestLeaves(root->right);

        
    }
};