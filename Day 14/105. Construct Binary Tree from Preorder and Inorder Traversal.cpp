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
    TreeNode* buildT(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap)
    {
        if(inStart > inEnd || preStart > preEnd)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);
        int idx = inMap[preorder[preStart]], sz = idx - inStart;

        root->left = buildT(preorder, preStart + 1, preStart + sz, inorder, inStart, idx - 1, inMap);
        root->right = buildT(preorder, preStart + sz + 1, preEnd, inorder, idx + 1, inEnd, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;
        int inStart = 0, inEnd = inorder.size() - 1, preStart = 0, preEnd = inEnd;
        for(int i = inStart; i <= inEnd; i++)
        {
            inMap[inorder[i]] = i; // Map to store index of elements in the inorder traversal
        }

        return buildT(preorder, preStart, preEnd, inorder, inStart, inEnd, inMap);
    }
};