/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    TreeLinkNode *next;
    bool dfs(TreeLinkNode *root, int height){
        if(root == NULL) return false;
        height --;
        if(height == 0){
            root->next = next;
            next = root;
            return true;
        }
        else{
            dfs(root->right, height);
            return dfs(root->left, height);
        }
    }
    void connect(TreeLinkNode *root) {
        int height = 0;
        do
        {
            next = NULL;
            height ++;
        }while(dfs(root, height));
    }
};
