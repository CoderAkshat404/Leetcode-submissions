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
    int maxLevelSum(TreeNode* root) {
        int maxi=-1e9;
        int ans=-1;
        queue<TreeNode*> q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            cnt++;
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=q.front()->val;
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            if(sum>maxi){
                maxi=sum;
                ans=cnt;
            }
        }
        return ans;
        
    }
};