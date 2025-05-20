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
TreeNode* solve(int poss,int pose,int ins,int ine,vector<int>& postorder, vector<int>& inorder,unordered_map<int,int>&m){
        if (poss > pose || ins > ine) {
            return nullptr;
        }
        TreeNode* x=new TreeNode(postorder[pose]);
        int numsright=ine-m[x->val];
        x->left=solve(poss,pose-numsright-1,ins,m[x->val]-1,postorder,inorder,m);
        x->right=solve(pose-numsright,pose-1,m[x->val]+1,ine,postorder,inorder,m);
        return x;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        for(int i=0;i<postorder.size();i++){
            m[inorder[i]]=i;
        }
        return solve(0,postorder.size()-1,0,inorder.size()-1,postorder,inorder,m);
        
    }
};