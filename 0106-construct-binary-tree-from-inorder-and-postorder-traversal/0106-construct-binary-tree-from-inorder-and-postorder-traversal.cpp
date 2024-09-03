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
    int find(int element,vector<int>& inorder){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==element){
                return i;
            }

        }
        return -1;
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int & index,int inorders,int inordere,int size){
        if(index<0 || inorders>inordere){
            return NULL;
        }
        int element=postorder[index--];
        TreeNode*root=new TreeNode(element);
        int pos=find(element,inorder);
        root->right=solve(inorder,postorder,index,pos+1,inordere,size);
        root->left=solve(inorder,postorder,index,inorders,pos-1,size);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size=postorder.size();
        int index=size-1;
        int inorders=0;
        int inordere=size-1;
        TreeNode*root=solve(inorder,postorder,index,inorders,inordere,size);
        return root;
        
    }
};