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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode *x=new TreeNode(val);
            return x;
        }
         TreeNode* temp=root;
        while(root){
            if(root->val>val){
                if(root->left==NULL)
                {
                    TreeNode *x=new TreeNode(val);
                    root->left=x;
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right==NULL)
                {
                    TreeNode *x=new TreeNode(val);
                    root->right=x;
                    break;
                }
                else{
                    root=root->right;

                }

            }
        }
        return temp;
        
    }
};