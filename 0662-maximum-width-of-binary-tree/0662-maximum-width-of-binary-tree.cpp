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
#define ll long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        ll maxi=INT_MIN;
        while(!q.empty()){
            TreeNode* node=q.front().first;
            ll mini=q.front().second;
            ll sz=q.size();
            ll left;
            ll right;
            for(int i=0;i<sz;i++){
                if(i==0) left=q.front().second;
                if(i==sz-1) right=q.front().second;;
                TreeNode* temp=q.front().first;
                int level=q.front().second-mini;
                q.pop();
                if(temp->left){
                    q.push({temp->left,(ll)((level*2LL)+1LL)});
                }
                if(temp->right){
                    q.push({temp->right,(ll)((level*2LL)+2LL)});

                }
            }
            maxi=max(maxi,right-left+1);
        }
      return maxi;  
    }
};