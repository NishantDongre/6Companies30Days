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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {

        if (!root)
            return NULL;

        int val = root->val;

        if (high < val)
        {
            TreeNode *res = trimBST(root->left, low, high);
            root->left = res;
            return res;
        }
        if (val < low)
        {
            TreeNode *res = trimBST(root->right, low, high);
            root->right = res;
            return res;
        }

        if (low <= val and val <= high)
        {
            TreeNode *left = trimBST(root->left, low, high);
            TreeNode *right = trimBST(root->right, low, high);

            root->left = left;
            root->right = right;

            return root;
        }
        return NULL;
    }
};