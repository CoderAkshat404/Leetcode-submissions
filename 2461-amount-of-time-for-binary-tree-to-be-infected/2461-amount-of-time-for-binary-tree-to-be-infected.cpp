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
TreeNode* x;
void solve(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &m,TreeNode* p){
        if(root==NULL) return;
        m[root]=p;
        solve(root->left,m,root);
        solve(root->right,m,root);

}
void f(TreeNode* root,int target){
    if(root==NULL){
        return;
    }
    if(root->val==target){
        x=root;
        return ;
    }
    f(root->left,target);
    f(root->right,target);
}
    int amountOfTime(TreeNode* root, int target) {
        unordered_map<TreeNode*,TreeNode*> m;
        solve(root,m,NULL);
        f(root,target);
        unordered_map<TreeNode*,bool> vis;
        queue<pair<TreeNode*,int>> q;
        q.push({x,0});
        vis[x]=1;
        int maxi=INT_MIN;
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int level=q.front().second;
            q.pop();
            maxi=max(maxi,level);
            if(vis[node->left]==false && node->left!=NULL ){
                vis[node->left]=1;
                q.push({node->left,level+1});
            }
            if(vis[node->right]==false && node->right!=NULL){
                vis[node->right]=1;
                q.push({node->right,level+1});
            }
            if(vis[m[node]]==false && m[node]!=NULL){
                vis[m[node]]=1;
                q.push({m[node],level+1});
            }
        }
        return maxi;
        
    }
};