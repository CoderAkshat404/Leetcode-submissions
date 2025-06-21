/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &m,TreeNode* p){
        if(root==NULL) return;
        m[root]=p;
        solve(root->left,m,root);
        solve(root->right,m,root);

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> m;
        solve(root,m,NULL);
        unordered_map<TreeNode*,bool> vis;
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        vis[target]=1;
        vector<int> ans;
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int level=q.front().second;
            q.pop();
            if(level==k){
                ans.push_back(node->val);
            }
            if(level+1<=k && vis[node->left]==false && node->left!=NULL ){
                vis[node->left]=1;
                q.push({node->left,level+1});
            }
            if(level+1<=k && vis[node->right]==false && node->right!=NULL){
                vis[node->right]=1;
                q.push({node->right,level+1});
            }
            if(level+1<=k && vis[m[node]]==false && m[node]!=NULL){
                vis[m[node]]=1;
                q.push({m[node],level+1});
            }
        }
        return ans;

        
    }
};