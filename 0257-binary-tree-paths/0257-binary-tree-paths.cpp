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
    void solve(vector<string>&ans,string &s,TreeNode* root){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            int x=root->val;
            string p=to_string(x);
            s+=p;
            ans.push_back(s);
            int y=p.length();
            while(y--){
                s.pop_back();
            }
            return ;

        }
        int x=root->val;
        string p=to_string(x);
        s+=p;
        s.push_back('-');
        s.push_back('>');
        solve(ans,s,root->left);
        solve(ans,s,root->right);
        s.pop_back();
        s.pop_back();
         int y=p.length();
        while(y--){
                s.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s="";
        solve(ans,s,root);
        return ans;
        
    }
};