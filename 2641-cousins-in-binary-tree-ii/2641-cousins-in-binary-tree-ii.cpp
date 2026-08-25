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
     void solve(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &m,TreeNode* p){
        if(root==NULL) return;
        m[root]=p;
        solve(root->left,m,root);
        solve(root->right,m,root);

    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        TreeNode*ans=root;
        unordered_map<TreeNode*,TreeNode*> m;
        unordered_map<TreeNode*,bool> vis;
        solve(root,m,NULL);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            int sum=0;
            vector<TreeNode*> v;
            for(int i=0;i<sz;i++){
                sum+=q.front()->val;
                v.push_back(q.front());
                q.pop();
            }
            for(auto i:v){
                if(i->right){
                    q.push(i->right);
                }
                if(i->left){
                    q.push(i->left);
                }
                if(vis[i]==1)continue;
                if(m[i]==NULL) continue;
                TreeNode*temp=m[i];
                int x=sum;
                if(temp->left){
                    x-=temp->left->val;
                }
                
                if(temp->right){
                    x-=temp->right->val;
                }
                if(temp->left){
                      temp->left->val=x;
                       vis[ temp->left]=1;
                }
                
                if(temp->right){
                  temp->right->val=x;
                   vis[temp->right]=1;
                }
                
               
            

            }
        }
        root->val=0;
        return root;
        
    }
};