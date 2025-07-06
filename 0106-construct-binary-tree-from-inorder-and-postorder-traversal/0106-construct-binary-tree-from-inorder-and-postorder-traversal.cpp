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
    TreeNode* solve(int ins,int inend,int poss,int posend,vector<int>& inorder, vector<int>& postorder){
        if(ins>inend){
            return NULL;
        }  
        if(ins==inend){
            TreeNode* x=new TreeNode(inorder[ins]);
            return x;
        }
        TreeNode* root=new TreeNode(postorder[posend]);
        int idx=m[postorder[posend]];
        root->left = solve(ins, idx - 1, poss, poss + idx - ins - 1, inorder, postorder);

        root->right=solve(idx+1,inend,poss+(idx-ins),posend-1,inorder,postorder);
        return root;


    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        m.clear();  
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return solve(0,inorder.size()-1,0,postorder.size()-1,inorder,postorder);
        
    }
};