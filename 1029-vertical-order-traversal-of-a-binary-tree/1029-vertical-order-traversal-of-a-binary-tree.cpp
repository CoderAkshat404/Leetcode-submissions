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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> m;
        if(root==NULL) return {};
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* temp=q.front().first;
            int hori=q.front().second.first;
            int vert=q.front().second.second;
            q.pop();
            m[vert][hori].push_back(temp->val);
            if(temp->left){
                q.push({temp->left,{hori+1,vert-1}});
            }
            if(temp->right){
                q.push({temp->right,{hori+1,vert+1}});

            }

        }
        vector<vector<int>> ans;
        for(auto i:m){
            vector<int> v;
            for(auto j:i.second){
                vector<int> k=j.second;
                sort(k.begin(),k.end());
                for(int p=0;p<k.size();p++){
                    v.push_back(k[p]);
                }
            }
            ans.push_back(v);
        }
        return ans;


        
    }
};