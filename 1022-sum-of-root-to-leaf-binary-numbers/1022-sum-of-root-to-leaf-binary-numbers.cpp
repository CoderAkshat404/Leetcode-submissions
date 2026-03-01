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
    string curr="";
    int ans=0;
    void convert(string s){
        reverse(s.begin(),s.end());
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                ans+=(1<<i);   
            }
        }
    }
    void solve(TreeNode* root){
        if(root==NULL){
            curr+='0';
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            curr+=(root->val+'0');
            convert(curr);
            return;
        }
        curr+=(root->val+'0');
        solve(root->left);
        curr.pop_back();
        solve(root->right);
        curr.pop_back();
        
    }
    int sumRootToLeaf(TreeNode* root) {
        solve(root);
        return ans;
        
    }
};