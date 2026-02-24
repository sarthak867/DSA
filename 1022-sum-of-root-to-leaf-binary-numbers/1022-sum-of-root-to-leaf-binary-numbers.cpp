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
    int decimal (string s){
        int n =0;
        int j=0;
        for(int i =s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                n += (1<<j);
            }
            j++;
        }
        return n;
    }
vector<string> binary;
    void bin(TreeNode* root, string curr){
        if(root==NULL) return;
        if(root->right== NULL && root->left==NULL) {
            curr += root->val + '0';
            binary.push_back(curr);
            return;
        }
        curr += root->val + '0';
        bin(root->left,curr);
        bin(root->right,curr);
    }

    int sumRootToLeaf(TreeNode* root) {
        bin(root, "");
        int ans = 0;
        for(string s : binary){
            ans += decimal(s);
        }
        return ans;
    }
};