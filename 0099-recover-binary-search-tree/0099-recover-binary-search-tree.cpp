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
    TreeNode* prev=new TreeNode(INT_MIN);
    TreeNode* first=NULL;
    TreeNode* middle=NULL;
    TreeNode* last=NULL;
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        }
        solve(root->left);
        if(root->val<prev->val && middle==NULL){
            first=prev;
            middle=root;

        }
        else if(root->val<prev->val){
            last=root;
        }
        prev=root;
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        solve(root);
        if(first && last){
            swap(first->val,last->val);
        }
        else if(first && middle){
            swap(first->val,middle->val);

        }

        
    }
};