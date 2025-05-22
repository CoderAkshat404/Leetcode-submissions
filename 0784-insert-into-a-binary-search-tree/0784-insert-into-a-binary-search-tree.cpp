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
    void findans(TreeNode* root, int X,int &mini){
    if(root==NULL){
        return;
    }
    if(root->val==X){
        mini=0;
        return ;
    }
    if(root->val>X){
        findans(root->left,X,mini);
    }
    if(root->val<X){
        mini=min(mini,X-root->val);
        findans(root->right,X,mini);
    }
    }
    void makechanges(TreeNode*& root, int newval,int val){
        if(root==NULL){
            return;
        }
        if(root->val==newval){
            TreeNode*temp=root->right;
            TreeNode* x=new TreeNode(val);
            root->right=x;
            x->right=temp;
            return;
        }
        if(root->val>newval){
            makechanges(root->left,newval,val);
        }
        else{
            makechanges(root->right,newval,val);

        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        int mini=1e9;
        findans(root,val,mini);
        if(mini==1e9){
            TreeNode* x=new TreeNode(val);
            x->right=root;
            return x;
        }
        else{
            int newval=val-mini;
            makechanges(root,newval,val);
            return root;
        }

        
    }
};