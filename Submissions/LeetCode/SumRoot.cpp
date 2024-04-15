class Solution
{
public:
    // valor acumulado
    int runTree(TreeNode *root, int v, int sum)
    {
        // obtendo num final
        if (!root)
            return sum;

        if (!root->left && !root->right)
            return v * 10 + root->val;

        // computar no atual e recursividade
        return runTree(root->left, v * 10 + root->val, sum) + runTree(root->right, v * 10 + root->val, sum);
    }

    int sumNumbers(TreeNode *root)
    {
        return runTree(root, 0, 0);
    }
};