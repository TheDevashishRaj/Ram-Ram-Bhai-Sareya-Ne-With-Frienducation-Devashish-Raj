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
    void solve(TreeNode* root, int v, int &c)
    {
        if(root == NULL)
        {
            return;
        }

        if(root->val >= v)
        {
            c++;
            v = root->val;
        }
        solve(root->left, v, c);
        solve(root->right, v, c);
    }
    
    int goodNodes(TreeNode* root) {
        int c = 0;
        solve(root, root->val, c);
        return c;
    }
};