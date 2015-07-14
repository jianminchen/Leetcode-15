/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode* cur = stk.top();
            stk.pop();
            if(cur != NULL)
            {
                ret.push_back(cur->val);
                stk.push(cur->right);
                stk.push(cur->left);
            }
        }
        return ret;
    }
};
