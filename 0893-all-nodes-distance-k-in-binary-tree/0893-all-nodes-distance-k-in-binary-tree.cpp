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
        queue<pair<TreeNode*,int>> q;
        unordered_map<TreeNode*,bool> mp;
        q.push({target,0});
        mp[target]=true;
        vector<int> ans;
        
        while(!q.empty()){
            int d=q.front().second;
            TreeNode* temp=q.front().first;
            q.pop();
            if(d==k){
                ans.push_back(temp->val);
            }
            if(temp->left){
                if(d+1<=k && mp[temp->left]==false){
                    q.push({temp->left,d+1});
                    mp[temp->left]=true;
                }
                
            }
            if(temp->right){
                if(d+1<=k && mp[temp->right]==false){ 
                q.push({temp->right,d+1});
                mp[temp->right]=true;}

            }
            if(m[temp]){
                if(d+1<=k && mp[m[temp]]==false){
                q.push({m[temp],d+1});
                mp[m[temp]]=true;
                }
                
            }

        }
        return ans;

        
    }
};