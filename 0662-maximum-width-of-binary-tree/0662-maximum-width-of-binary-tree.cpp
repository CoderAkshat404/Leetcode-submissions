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
int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long maxi = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0}); // Start index from 0

        while (!q.empty()) {
            int sz = q.size();
            long long left = q.front().second;  // Get the first element's index
            long long right = q.back().second; // Get the last element's index

            maxi = max(maxi, right - left + 1);  // Calculate width at this level

            for (int i = 0; i < sz; i++) {
                auto [node, idx] = q.front();
                q.pop();

                long long newIdx = idx - left; // Normalize index to avoid overflow

                if (node->left) q.push({node->left, 2 * newIdx});
                if (node->right) q.push({node->right, 2 * newIdx + 1});
            }
        }
        return maxi;
    }

};