/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* x=q.front();
            q.pop();
            if(x==NULL){
                s.append("#,");
            }
            else{
                s.append(to_string(x->val)+',');
                q.push(x->left);
                q.push(x->right);
            }

        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* x=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                x->left=NULL;

            }
            else{
                TreeNode* y=new TreeNode(stoi(str));
                x->left=y;
                q.push(y);

            }
            getline(s,str,',');
            if(str=="#"){
                x->right=NULL;

            }
            else{
                TreeNode* y=new TreeNode(stoi(str));
                x->right=y;
                q.push(y);
            }
            
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));