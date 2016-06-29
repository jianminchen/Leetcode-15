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
    bool valid;
    bool first;
    int value;
    void isValidBSTHelper(TreeNode* root) {
        if(root == 0){
            return;
        }
        isValidBSTHelper(root->left);
        if(first){
            first = false;
            value = root->val;
        } else {
            if (root->val <= value){
                valid = false;
            }
            value = root->val;
        }
        isValidBSTHelper(root->right);
    }
    bool isValidBST(TreeNode* root) {
        first = true;
        valid = true;
        isValidBSTHelper(root);
        return valid;
    }
};
