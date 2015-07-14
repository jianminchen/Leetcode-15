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
    vector<TreeLinkNode *> traverse(TreeLinkNode *root){
        vector<TreeLinkNode *> ans;
        queue<TreeLinkNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeLinkNode * cur = q.front();
            q.pop();
            if(cur != NULL)
            {
                ans.push_back(cur);
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return ans;
    }
    void connect(TreeLinkNode *root) {
        vector<TreeLinkNode *> labels = traverse(root);
        for(int i = 0, j = 1 ;i < labels.size(); i ++){
            int vid = i + 1;
            if(vid == (1 << j) - 1){
                labels[i]->next = NULL;
                j ++;
            }
            else{
                labels[i]->next = labels[i + 1];
            }
        }
    }
};
