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
    void inorder(TreeNode* root, vector<int> &arr){
        if(root == nullptr)return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> arr; 
        inorder(root, arr);
        int n = arr.size();
        for(auto &val : queries){
            int i = lower_bound(arr.begin(), arr.end(), val) - arr.begin();
            if(i < n && arr[i] == val){
                ans.push_back({val, val});
            }else if(i == 0){
                ans.push_back({-1, arr[i]});
            }else if(i == n){
                ans.push_back({arr[i-1], -1});
            }else{
                ans.push_back({arr[i-1], arr[i]});
            }
        }
        return ans;
    }
};