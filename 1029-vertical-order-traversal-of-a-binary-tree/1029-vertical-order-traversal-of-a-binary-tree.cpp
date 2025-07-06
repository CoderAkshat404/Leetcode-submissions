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
    map<int,map<int,multiset<int>>> m;
    void solve(TreeNode* root,int i,int j){
        if(root==NULL){
            return ;
        }
        m[i][j].insert(root->val);
        solve(root->left,i-1,j+1);
        solve(root->right,i+1,j+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root,0,0);
        vector<vector<int>> ans;
        for(auto i:m){
            vector<int> v;
            for(auto j:i.second){
                for(auto k:j.second){
                    v.push_back(k);
                }
            }
            ans.push_back(v);
        }
        return ans;
        
    }
};