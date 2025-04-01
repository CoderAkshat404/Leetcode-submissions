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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        map<int,int> m;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* temp=q.front().first;
            int h=q.front().second;
            q.pop();
            if(m.find(h)==m.end()){
                m[h]=temp->val;
            }
            if(temp->right){
                q.push({temp->right,h+1});
            }
            if(temp->left){
                q.push({temp->left,h+1});

            }
        }
        vector<int> ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
        
    }
};