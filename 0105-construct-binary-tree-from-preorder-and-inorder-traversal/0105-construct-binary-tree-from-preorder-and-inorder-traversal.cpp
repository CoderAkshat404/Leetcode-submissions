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
    unordered_map<int,int> m;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int instart,int inend,int prestart, int preend){
        if(prestart>preend){
            return NULL;
        }
        if(prestart==preend){
            TreeNode* root=new TreeNode(preorder[prestart]); 
            return root;   
        }
        TreeNode* root=new TreeNode(preorder[prestart]);
        int count=m[preorder[prestart]]-instart;
        root->left=solve(preorder,inorder,instart,m[preorder[prestart]]-1,prestart+1,prestart+count);
        root->right=solve(preorder,inorder,m[preorder[prestart]]+1,inend,prestart+count+1,preend);
        return root;



    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<preorder.size();i++){
            m[inorder[i]]=i;
        }
        
        return solve(preorder,inorder,0,preorder.size()-1,0,preorder.size()-1);
        
    }
};