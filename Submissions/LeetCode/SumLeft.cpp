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
class Solution
{
public:
    int runTree(TreeNode *root, bool left)
    {
        if (!root)
            return 0;
        if (left && !root->left && !root->right)
            return root->val;
        return runTree(root->left, 1) + runTree(root->right, 0);
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        return runTree(root->left, 1) + runTree(root->right, 0);
    }
};