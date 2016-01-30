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
	TreeNode* buildTree_helper(vector<int>::iterator inorder_begin, vector<int>::iterator inorder_end,
		vector<int>::iterator postorder_begin, vector<int>::iterator postorder_end) {
		int size = inorder_end - inorder_begin;
		int value = *(postorder_end - 1);
		TreeNode* node = new TreeNode(value);
		int leftSize = find(inorder_begin, inorder_end, value) - inorder_begin;
		int rightSize = size - leftSize - 1;
		if (leftSize > 0) {
			node->left = buildTree_helper(inorder_begin, inorder_begin + leftSize, postorder_begin, postorder_begin + leftSize);
		}
		if (rightSize > 0) {
			node->right = buildTree_helper(inorder_begin + leftSize + 1, inorder_end, postorder_begin + leftSize, postorder_end - 1);
		}
		return node;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0) return NULL;
		return buildTree_helper(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
	}
};
