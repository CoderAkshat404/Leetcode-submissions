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
    TreeNode*prev;
    TreeNode* first;
    TreeNode * middle;
    TreeNode* second;
    bool flag;
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        }
        solve(root->left);
        if(root->val<prev->val && flag==false){
            first=prev;
            middle=root;
            flag=true;
        }
        else if(root->val<prev->val && flag==true){
            flag=false;
            second=root;
        }
        prev=root;
        solve(root->right);
        
    }
    void recoverTree(TreeNode* root) {
        flag=false;
        prev=new TreeNode(INT_MIN);
        solve(root);
        if(flag==false){
            swap(first->val,second->val);
            return;
        }
        swap(first->val,middle->val);
        return ;
        
        
    }
};