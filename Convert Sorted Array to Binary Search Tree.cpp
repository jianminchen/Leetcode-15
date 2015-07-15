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
    template<class T>
    TreeNode* construct(T beg, T end){
        if(beg == end) return NULL;
        T mid = beg + (end - beg) / 2;
        TreeNode* curr  = new TreeNode(*mid);
        curr->left = construct(beg, mid);
        curr->right = construct(mid +1, end);
        return curr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return construct(begin(nums), end(nums));   
    }
};
