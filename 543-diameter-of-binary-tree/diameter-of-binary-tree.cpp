class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        diameterOfBinaryTreee(root, maxi);
        return maxi;
    }

    int diameterOfBinaryTreee(TreeNode* root, int& maxi) {
        if (root == NULL) return 0;

        int left  = maxDepth(root->left);
        int right = maxDepth(root->right);
        maxi = max(left + right, maxi);

        diameterOfBinaryTreee(root->left,  maxi);
        diameterOfBinaryTreee(root->right, maxi);
        return maxi;
    }

    int maxDepth(TreeNode* root) {       
        if (root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};