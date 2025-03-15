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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>> v(20001);
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* temp=q.front().first;
            int idx=q.front().second;
            q.pop();
            v[idx].push_back(temp->val);
            if(temp->left!=NULL){
                q.push({temp->left,idx+1});
            }
            if(temp->right!=NULL){
                q.push({temp->right,idx+1});
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<v.size();i++){
            if(v[i].size()>0){
                ans.push_back(v[i]);
            }
        }
        return ans;
        
    }
};