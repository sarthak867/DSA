class Solution {
public:
    vector<TreeNode*> nodes;

    void preorder(TreeNode* root){
        if(!root) return;
        nodes.push_back(root);
        preorder(root->left);
        preorder(root->right);
    }

    void flatten(TreeNode* root) {
        if(!root) return;

        preorder(root);

        for(int i = 0; i < nodes.size()-1; i++){
            nodes[i]->left = NULL;
            nodes[i]->right = nodes[i+1];
        }
    }
};
