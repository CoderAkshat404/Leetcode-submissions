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
    int lefth(TreeNode* root){
        int h=1;
        while(root){
            h++;
            root=root->left;
        }
        return h;
    }
    int righth(TreeNode* root){
        int h=1;
        while(root){
            h++;
            root=root->right;
        }
        return h;

    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int l=lefth(root->left);
        int r=righth(root->right);
        if(l==r) return (1<<l)-1;
        else return 1+countNodes(root->left)+countNodes(root->right);

        
    }
};