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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root == NULL) return ret;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* cur, *prev = root;
        while (!stk.empty()) {
            cur = stk.top();
            stk.pop();

            if (prev == cur->left){ // from left
                if(cur->right != NULL){
                    stk.push(cur);
                    stk.push(cur->right);
                }
                else{
                    ret.push_back(cur->val); 
                }
            }
            else if(prev == cur->right){ // from right
                ret.push_back(cur->val);
            }
            else{ // from root
                if(cur->left != NULL){
                    stk.push(cur);
                    stk.push(cur->left);
                }
                else{
                    if(cur->right != NULL){
                        stk.push(cur);
                        stk.push(cur->right);
                    }
                    else{
                        ret.push_back(cur->val); // leaf
                    }
                }
            }
            prev = cur;
        }
        return ret;
    }
};
