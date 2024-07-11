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
    int maxpath(TreeNode* root, int &mx)
    {
        if(root == NULL)
        {
            return 0;
        }

        int l = maxpath(root->left, mx), r = maxpath(root->right, mx);
        l = max(l, 0); // Ignoring negative paths
        r = max(r, 0); // Ignoring negative paths
        mx = max(mx, root->val + l + r);

        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        maxpath(root, mx);

        return mx;
    }
};