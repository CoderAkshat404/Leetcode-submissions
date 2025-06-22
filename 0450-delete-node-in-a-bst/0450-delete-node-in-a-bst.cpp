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
    TreeNode* deleteNode(TreeNode* root, int key) {
     
        if(root==NULL){
            return NULL;
        }
        TreeNode* temp=root;
        while(root){
            if(root->val==key){
                if(root->right){
                    TreeNode* x=root->left;
                    TreeNode* y = root->right;
                    while(y->left!=NULL){
                        y=y->left;
                    }
                    y->left=x;
                    temp=root->right;
                    break;
                    

                }
                else if(root->left){
                    temp=root->left;
                    break;
                }
                else{
                    return NULL;
                }

            }
            else if(root->left){
                if(root->left->val==key){
                    if(root->left->right){
                        TreeNode* x=root->left->left;
                        root->left=root->left->right;
                        
                        // FIXED: move to leftmost of new root->left
                        TreeNode* y = root->left;
                        while(y->left!=NULL){
                            y=y->left;
                        }
                        y->left=x; // attach preserved left subtree
                        break;    
                    }
                    else if(root->left->left){
                        TreeNode* x=root->left->left;
                        root->left=x;
                        break;
                    }
                    else{
                        root->left=NULL;
                        break;
                    }
                }
            }

            if(root->right && root->right->val==key){
                if(root->right->left){
                    TreeNode* x=root->right->right;
                    root->right=root->right->left;

                    // FIXED: move to rightmost of new root->right
                    TreeNode* y = root->right;
                    while(y->right!=NULL){
                        y=y->right;
                    }
                    y->right=x; // attach preserved right subtree
                    break;
                }
                else if(root->right->right){
                    TreeNode* x=root->right->right;
                    root->right=x;
                    break;
                }
                else{
                    root->right=NULL;
                    break;
                }
            }
            else{
                if(root->val>key){
                    root=root->left;
                }
                else{
                    root=root->right;
                }
            }
        }

        return temp;  
    }
};
