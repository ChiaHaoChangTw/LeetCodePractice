#include<iostream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(): val(0), left(nullptr), right(nullptr){}
	TreeNode(int x): val(x), left(nullptr), right(nullptr){}
	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

class Solution{
public:
	bool isValidBST(TreeNode* root){
		return checkBST(root, nullptr, nullptr);
	}

private:
	bool checkBST(TreeNode* root, TreeNode* maxNode, TreeNode* minNode){
		if(!root){return true;}
		if(maxNode && root->val >= maxNode->val || minNode && root->val <= minNode->val){return false;}
		return checkBST(root->left, root, minNode) && checkBST(root->right, maxNode, root);
	}
};

int main(){
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	
	Solution* solution = new Solution();
	
	cout << solution->isValidBST(root) << " [expected: 1]" << endl;
	
	return 0;
}
