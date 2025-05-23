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
    void dothat(TreeNode* & root, int key){
        if(root==NULL){
            return;
        }
        if(root->left!=NULL){
            if(root->left->val==key){
                TreeNode*temp=root->left;
                if(root->left->right){
                    root->left=root->left->right;
                    TreeNode* x=root->left;
                    while(x->left!=NULL){
                        x=x->left;

                    }
                    x->left=temp->left;
                    return;
                }
                else if(root->left->left){
                    root->left=root->left->left;
                    TreeNode* x=root->left;
                    while(x->right!=NULL){
                        x=x->right;
                    }
                    x->right=temp->right;
                    return;

                }
                else{
                    root->left=NULL;
                    return;
                }
            }
        }
        if(root->right!=NULL){
            if(root->right->val==key){
                TreeNode*temp=root->right;
                if(root->right->right){
                    root->right=root->right->right;
                    TreeNode* x=root->right;
                    while(x->left!=NULL){
                        x=x->left;

                    }
                    x->left=temp->left;
                    return;
                }
                else if(root->right->left){
                    root->right=root->right->left;
                    TreeNode* x=root->right;
                    while(x->right!=NULL){
                        x=x->right;
                    }
                    x->right=temp->right;
                    return;


                    
                    return;

                }
                else{
                    root->right=NULL;
                }

            }

        }
        if(root->val>key){
            dothat(root->left,key);
        }
        if(root->val<key){
            dothat(root->right,key);
        }
        if(root->val==key){
            if(root->right){
                TreeNode* x=root->right;
                TreeNode *temp=x;
                while(temp->left!=NULL){
                    temp=temp->left;
                }
                temp->left=root->left;
                root=x;
                return;
            }
            else if(root->left){
                TreeNode* x=root->left;
                TreeNode *temp=x;
                while(temp->right!=NULL){
                    temp=temp->right;
                }
                temp->right=root->right;
                root=x;
                return;

            }
            else{
                root=NULL;
                return;
            }
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        dothat(root,key);
        return root;
        
    }
};