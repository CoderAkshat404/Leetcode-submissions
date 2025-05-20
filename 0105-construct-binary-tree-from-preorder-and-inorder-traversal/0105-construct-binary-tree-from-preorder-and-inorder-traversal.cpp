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
    TreeNode* solve(int pres,int pree,int ins,int ine,vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>&m){
        if (pres > pree || ins > ine) {
    return nullptr;
}
        TreeNode* x=new TreeNode(preorder[pres]);
        int numsleft=m[x->val]-ins;
        x->left=solve(pres+1,pres+numsleft,ins,m[x->val]-1,preorder,inorder,m);
        x->right=solve(pres+numsleft+1,pree,m[x->val]+1,ine,preorder,inorder,m);
        return x;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return solve(0,preorder.size()-1,0,inorder.size()-1,preorder,inorder,m);

        
    }
};