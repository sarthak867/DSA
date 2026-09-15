class Solution {
public:
    int cameras = 0;

    // 0 = needs camera
    // 1 = has camera
    // 2 = covered
    int dfs(TreeNode* root) {
        if (root == NULL)
            return 2;

        int left = dfs(root->left);
        int right = dfs(root->right);

        // If any child needs a camera,
        // put camera at current node
        if (left == 0 || right == 0) {
            cameras++;
            return 1;
        }

        // If any child has a camera,
        // current node is covered
        if (left == 1 || right == 1) {
            return 2;
        }

        // Both children are covered but
        // neither has a camera
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0)
            cameras++;

        return cameras;
    }
};