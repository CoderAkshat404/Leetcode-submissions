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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*> q;
        int count=0;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            count++;
            vector<int> v;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                v.push_back(node->val);
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                
            }
            if(count%2==0){
                reverse(v.begin(),v.end());
                ans.push_back(v);

            }
            else{
                ans.push_back(v);
            }

        }
        return ans;
        
    }
};