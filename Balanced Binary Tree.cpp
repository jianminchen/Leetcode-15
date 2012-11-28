/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode *root)
    {
        if(root == 0) return 0;
        int h1 = dfs(root->left), h2 = dfs(root->right);
        if(abs(h1- h2) > 1) throw false;
        return max(h1,h2) + 1;
    }
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        try
        {
            dfs(root);
        }
        catch(bool ex)
        {
            return ex;
        }
        return true;
    }
};