class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		if (root == NULL) return ret;
		stack<TreeNode*> stk;
		stk.push(root);
		TreeNode* cur, *prev = root;
		while (!stk.empty()) {
			cur = stk.top();
			stk.pop();

			if (prev == cur->left){ // from left
			    ret.push_back(cur->val);
			    if(cur->right != NULL){
			        stk.push(cur);
			        stk.push(cur->right);
			    }
			}
			else if(prev == cur->right){ // from right
			    ; // do nothing
			}
			else{ // from root
			    if(cur->left != NULL){
			        stk.push(cur);
			        stk.push(cur->left);
			    }
			    else{
			        if(cur->right != NULL){
			            ret.push_back(cur->val);
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
