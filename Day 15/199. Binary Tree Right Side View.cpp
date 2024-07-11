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
    void fun(TreeNode* root, int l, vector<int> &a)
    {
        if(root == NULL)
        {
            return;
        }

        if(l == a.size()) // First Time Coming to Level l
        {
            a.push_back(root->val);
        }
        fun(root->right, l + 1, a);
        fun(root->left, l + 1, a);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
        {
            return ans;
        }

        // // Level order traversal logic
        // queue<TreeNode*> q;
        // q.push(root);

        // while(!q.empty())
        // {
        //     int sz = q.size();
        //     for(int i = 0; i < sz; i++)
        //     {
        //         auto t = q.front();
        //         q.pop();

        //         if(i == 0)
        //         {
        //             ans.push_back(t->val);
        //         }

        //         if(t->right != NULL)
        //         {
        //             q.push(t->right);
        //         }

        //         if(t->left != NULL)
        //         {
        //             q.push(t->left);
        //         }
        //     }
        // }

        // Recursive Logic
        fun(root, 0, ans);

        return ans;
    }
};